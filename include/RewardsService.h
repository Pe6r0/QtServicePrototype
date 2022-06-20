#pragma once
#include <vector>
#include <optional>

#include <QWidget>
#include <QPointer>

#include "Comm.h"
#include "Service.h"
#include "EligibilityService.h"

namespace services
{
    //@brief main class for the rewards service. Like all services, it needs to be running before it will be working.
    // intended workflow: 
    // * set up a eligibility service calling setEligibityService
    // * start both services
    // * connect to both rewardsCheck port and rewardsAvailable signal
    // * emit
class RewardsService : public Service {
    Q_OBJECT
public:
    struct RewardsServiceReply
    {
        services::AccountNumber _number = services::cInvalidNumber;
        std::vector <services::Reward> _rewards;
    };

    RewardsService(QObject* parent = nullptr);

    ~RewardsService();

    void setEligibityService(EligibilityService& service);

    std::optional<Reward> getReward(const Channel c);

signals:
    void rewardsAvailable(RewardsServiceReply results);
    void eligibilityCheck(AccountNumber i);

public slots:
    void eligibilityGiven(EligibilityService::Output value);
    void rewardsCheck(const AccountNumber number, std::vector<Channel> channels);

private:
    QPointer<EligibilityService> _eligibilityService;  //Does not manage this object
    std::unordered_map<AccountNumber, std::vector<Channel>> _ongoingRequests;
    const static std::map<Channel, Reward> _cRewards;
};

} // namespace services
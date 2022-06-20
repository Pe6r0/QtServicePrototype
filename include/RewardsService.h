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

    class RewardsService : public Service {
      Q_OBJECT
    public:
        RewardsService(QObject* parent = nullptr);

        ~RewardsService();

        void setEligibityService(EligibilityService& service);

        std::optional<Reward> getReward(const Channel c);

    signals:
        void rewardsAvailable(AccountNumber number, std::vector<Reward> results);
        void eligibilityCheck(AccountNumber i);

    public slots:
        void eligibilityGiven(EligibilityService::Output value);
        void rewardsCheck(const AccountNumber number, std::vector<Channel> channels);

    private:
        QPointer<EligibilityService> _eligibilityService;
        std::map<AccountNumber, std::vector<Channel>> _ongoingRequests;
        std::map<Channel, Reward> _rewards;
    };

} // namespace services
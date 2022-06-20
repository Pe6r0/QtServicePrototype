#pragma once
#include <QWidget>
#include <QPointer>

#include "Comm.h"
#include "Service.h"

//TODO: Eligibility Service currently in development. For Testing purposes it just replies based on account number parity. [add US link here]
namespace services 
{
class RewardsService;

class EligibilityService : public Service {
    Q_OBJECT
public:
    struct Output
    {
        enum class Type
        {
            CUSTOMER_ELIGIBLE,
            CUSTOMER_INELIGIBLE,
            ERROR
        };

        AccountNumber _number{ cInvalidNumber };
        Type _type{ Type::ERROR };
    };

    EligibilityService(QObject* parent = nullptr);

    ~EligibilityService();

    void setRewardsService(RewardsService& service);

signals:
    void eligibility(Output value);

public slots:
    void checkEligibility(const AccountNumber number);

private:
    QPointer<RewardsService> _rewardsService;
};
} // namespace services
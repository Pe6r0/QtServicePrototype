#pragma once
#include <vector>

#include <QWidget>
#include <QPointer>

#include "Service.h"
#include "ServiceManager.h"
#include "EligibilityService.h"

namespace services {

using AccountNumber = size_t;

class RewardsService : public Service {
  Q_OBJECT
public:
    RewardsService(QObject* parent = nullptr);

    //bool setEligibityService(Service &reporter);
    Reward myRewards;

public slots:

    //std::vector<Reward> getRewards(const AccountNumber accountNumber, std::vector<Channel>); //use signals to communicate instead of direct calls (add wait here, maybe timeout)

//public signals:
    //void rewards(std::vector<Reward> results);

private:
    QPointer<EligibilityService> _eligibilityService;
};

} // namespace services
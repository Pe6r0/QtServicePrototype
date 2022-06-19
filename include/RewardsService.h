#pragma once
#include <QWidget>
#include <vector>
//#include <optional>

#include "../include/Service.h"
#include "../include/EligibilityService.h"

namespace services {
/*
using AccountNumber = size_t;

struct Reward
{
    std::string test;
};

class RewardsService : public Service {
  Q_OBJECT
public:
    RewardsService(QObject* parent = nullptr);

    bool setEligibityService(Service &reporter);

public slots:
    std::optional<std::vector<Reward>> eligibility(AccountNumber accountNumber); //use signals to communicate instead of direct calls (add wait here, maybe timeout)

//public signals:
    //void rewards(std::vector<Reward> results);

private:
    QPointer<QObject> _eligibilityService;
};
*/
} // namespace services
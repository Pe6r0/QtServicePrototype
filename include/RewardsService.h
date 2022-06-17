#pragma once
#include <QWidget>
#include <vector>
//#include <optional>

#include "../include/Service.h"
#include "../include/EligibilityService.h"

namespace services {

enum class Reward { FIRST, PREMIUM, BASIC };

enum class Subscriptions { TEST, KIDS };

class RewardsService : public Service {
  Q_OBJECT
public:
  RewardsService(QObject &reporter); // data input, check move etc

  void setEligibityService(QObject &reporter);
  
  /*std::optional<*/std::vector<Reward>/*>*/ query(size_t accountNumber, std::vector<Subscriptions> subs); //use signals to communicate instead of direct calls (add wait here, maybe timeout)
private:
    QPointer<QObject> _eligibilityService;
};

} // namespace services
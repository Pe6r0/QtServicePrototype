#pragma once
#include <QWidget>
#include <vector>
//#include <optional>

namespace services {
enum class Reward { FIRST, PREMIUM, BASIC };

enum class Subscriptions { TEST, KIDS };

class RewardsService : public QObject {
  Q_OBJECT
public:
  RewardsService(); // data input, check move etc
  
  /*std::optional<*/std::vector<Reward>/*>*/ query(size_t accountNumber, std::vector<Subscriptions> subs); //use signals to communicate instead of direct calls
private:
    
};

} // namespace services
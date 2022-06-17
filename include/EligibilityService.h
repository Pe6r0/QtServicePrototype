#pragma once
#include <QWidget>
#include <vector>
//#include <optional>

#include "../include/Service.h"
#include "../include/RewardsService.h"

namespace services {
    class EligibilityService : public Service {
        Q_OBJECT
    public:
        EligibilityService(QObject &rewardsService); // data input, check move etc

        void setRewardsService(QObject &rewardsService);

        /*std::optional<*/std::vector<Reward>/*>*/ query(size_t accountNumber, std::vector<Subscriptions> subs); //use signals to communicate instead of direct calls (add wait here, maybe timeout)
    private:
        QPointer<QObject> _eligibilityService;
    };

} // namespace services
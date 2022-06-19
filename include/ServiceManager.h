#pragma once
#include <QObject>
#include <QPointer>
#include <QJsonDocument>
#include <map>

#include "../include/EligibilityService.h"
#include "../include/RewardsService.h"
#include "../include/Service.h"

namespace services {
    /*enum class ServicesType
    {
        REWARDS_SERVICE,
        ELIGIBILITY_SERVICE //TODO PP: in development :)
    };

    //@brief: contains all the service communication logic.
    class ServiceManager : public QObject {
        Q_OBJECT
    public:
        bool setupServices(const QJsonDocument& setup);

        void startAllServices();

        void stopAllServices();

        std::map<ServicesType,bool> status();

    private:

        EligibilityService _eligibilityService;
        RewardsService _rewardsService;

    };
    */
} // namespace services
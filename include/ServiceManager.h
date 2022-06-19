#pragma once
#include <QObject>
#include <QPointer>

#include "Comm.h"
#include "RewardsService.h"
#include "EligibilityService.h"


namespace services {

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
    
} // namespace services
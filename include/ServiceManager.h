#pragma once
#include <unordered_map>
#include <string>

#include <QObject>
#include <QString>
#include <QPointer>

#include "Service.h"
#include "EligibilityService.h"
#include "RewardsService.h"


namespace services {
    enum class ServicesType
    {
        REWARDS_SERVICE,
        ELIGIBILITY_SERVICE //TODO PP: in development :)
    };

    enum class Reward
    {
        CHAMPIONS,
        KARAOKE,
        PIRATES
    };

    enum class Channel
    {
        SPORTS,
        KIDS,
        MUSIC,
        NEWS,
        MOVIES
    };

    static std::string rewardToString(const Reward t);
    static std::string channelToString(const Channel t);

    //@brief: contains all the service communication logic.
    class ServiceManager : public QObject {
        Q_OBJECT
    public:
        bool setupServices(const QJsonDocument& setup);

        void startAllServices();

        void stopAllServices();

        //std::map<ServicesType,bool> status();

    private:

        //EligibilityService _eligibilityService;
        //RewardsService _rewardsService;

    };
    
} // namespace services
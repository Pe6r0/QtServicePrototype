#pragma once

#pragma once
#include <string>

namespace services {

    using AccountNumber = size_t;

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

    std::string rewardToString(const Reward t);
    std::string channelToString(const Channel t);
}
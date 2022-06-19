#include "ServiceManager.h"

#include <iostream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace services {


static const std::unordered_map<Reward, QString> rewardsNames{ {Reward::CHAMPIONS, QObject::tr("Champions League Ticket Final")},
                                                                {Reward::KARAOKE, QObject::tr("Karaoke Pro Microphone") },
                                                                {Reward::PIRATES, QObject::tr("Pirates of the Caribean Collection")} };

static const std::unordered_map<Channel, QString> channelNames{ {Channel::SPORTS, QObject::tr("Sports")},
                                                                {Channel::KIDS, QObject::tr("Kids") },
                                                                {Channel::MUSIC, QObject::tr("Music")},
                                                                {Channel::NEWS, QObject::tr("News")} ,
                                                                {Channel::MOVIES, QObject::tr("Movies")} };

std::string rewardToString(const Reward t)
{
    assert(rewardsNames.find(t) != rewardsNames.end());
    return (*rewardsNames.find(t)).second.toStdString();
}

std::string channelToString(const Channel t)
{
    assert(channelNames.find(t) != channelNames.end());
    return (*channelNames.find(t)).second.toStdString();
}

bool ServiceManager::setupServices(const QJsonDocument& setup)
{
    const auto root = setup.object();

    const auto rewards = root["Rewards"].toArray();
    const auto channels = root["Channels"].toArray();

    for (const auto& channelIter : channels)
    {
        const auto channel = channelIter.toString();
        qDebug() << channel;

        if (!channel.isEmpty())
        {

        }
        else
        {
            qDebug() << "[warning] Malformed json file in channels. Attempting to continue.";
        }
    }

    for (const auto& rewardIter : rewards)
    {
        const auto reward = rewardIter.toObject();
        const auto channel = reward["Channel"].toString();
        const auto title = reward["Title"].toString();

        qDebug() << title;
        qDebug() << channel;
    }
    
    return true;
}

void ServiceManager::startAllServices()
{

}

void ServiceManager::stopAllServices()
{

}

std::map<ServicesType, bool> status()
{
    return {};
}
}

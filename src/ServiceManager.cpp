#include "../include/ServiceManager.h"

#include <iostream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace services {
    /*
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

}*/
}

#include "Comm.h"

#include <unordered_map>

#include <QObject>
#include <QString> 

namespace services
{
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

}

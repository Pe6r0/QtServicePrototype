#include "RewardsService.h"
#include <QObject>


using namespace services;

RewardsService::RewardsService(QObject* parent) : Service(parent)
{
    _rewards = {
           {Channel::SPORTS, Reward::CHAMPIONS },
           {Channel::MUSIC, Reward::KARAOKE },
           {Channel::MOVIES, Reward::PIRATES } }; //TODO make static
}

RewardsService::~RewardsService()
{}

std::optional<Reward> RewardsService::getReward(const Channel c)
{
    const auto t = _rewards.find(c);
    
    return t != _rewards.end() ? std::optional<Reward>{t->second} : std::nullopt;
}

void RewardsService::eligibilityGiven(EligibilityService::Output value)
{
    qDebug() << "[RewardsService] eligibility received.";

    std::vector<Reward> results;
    if (value._type == EligibilityService::Output::Type::CUSTOMER_ELIGIBLE) {
        if (_ongoingRequests.find(value._number) == _ongoingRequests.end())
        {
            qDebug() << "[RewardsService] malformed data packet received.";
            emit rewardsAvailable(value._number, results);
        }
        for (const auto& channel : _ongoingRequests[value._number])
        {
            const auto reward = getReward(channel);
            if (reward)
            {
                results.push_back(*reward);
            }
        }
    }
    qDebug() << "[RewardsService] emitting rewards.";
    emit(rewardsAvailable(value._number, results));
}


void RewardsService::rewardsCheck(const AccountNumber number, std::vector<Channel> channels)
{
    if (!_eligibilityService)
    {
        qDebug() << "No eligibility service set. Request cannot proceed";
        return;
    }

    _ongoingRequests[number] = channels;
    qDebug() << "[RewardsService] emitting eligibility check";
    emit(eligibilityCheck(number));
}

void RewardsService::setEligibityService(EligibilityService& elegibilityService)
{
    if (!_eligibilityService)
    {
        //TODO disconnect everything
    }
    _eligibilityService = &elegibilityService;

    connect(this, &RewardsService::eligibilityCheck, _eligibilityService, &EligibilityService::checkEligibility);

    elegibilityService.setRewardsService(*this);
}
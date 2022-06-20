#include "RewardsService.h"
#include <QObject>

namespace services
{

const std::map<Channel, Reward> RewardsService::_cRewards = {
        {Channel::SPORTS, Reward::CHAMPIONS },
        {Channel::MUSIC, Reward::KARAOKE },
        {Channel::MOVIES, Reward::PIRATES } };

RewardsService::RewardsService(QObject* parent) : Service(parent)
{}

RewardsService::~RewardsService()
{}

std::optional<Reward> RewardsService::getReward(const Channel c)
{
    const auto t = _cRewards.find(c);
    
    return t != _cRewards.end() ? std::optional<Reward>{t->second} : std::nullopt;
}

void RewardsService::eligibilityGiven(EligibilityService::Output value)
{
    std::vector<Reward> results;
    if (value._type == EligibilityService::Output::Type::CUSTOMER_ELIGIBLE) {
        if (_ongoingRequests.find(value._number) == _ongoingRequests.end())
        {
            qDebug() << "[RewardsService] malformed data packet received.";
            emit rewardsAvailable({ value._number, results });
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
    emit(rewardsAvailable(RewardsServiceReply{value._number, results}));
}

void RewardsService::rewardsCheck(const AccountNumber number, std::vector<Channel> channels)
{
    if (!_eligibilityService)
    {
        qDebug() << "No eligibility service set. Request cannot proceed.";
        return;
    }
    if (number == cInvalidNumber)
    {
        qDebug() << "Improper number. Request cannot proceed.";
        return;
    }

    _ongoingRequests[number] = channels;
    emit(eligibilityCheck(number));
}

void RewardsService::setEligibityService(EligibilityService& elegibilityService)
{
    if (!_eligibilityService)
    {
        disconnect(this, &RewardsService::eligibilityCheck, _eligibilityService, &EligibilityService::checkEligibility);
    }
    _eligibilityService = &elegibilityService;

    connect(this, &RewardsService::eligibilityCheck, _eligibilityService, &EligibilityService::checkEligibility);
    elegibilityService.setRewardsService(*this);
}
}
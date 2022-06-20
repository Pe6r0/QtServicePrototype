#include "EligibilityService.h"
#include "RewardsService.h"

namespace services
{

EligibilityService::EligibilityService(QObject* parent) : Service(parent)
{}

EligibilityService::~EligibilityService() {}

void EligibilityService::checkEligibility(const AccountNumber number)
{
    if (number <= 0)
    {
        qDebug() << "[EligibilityService] Problematic account number.";
        emit(eligibility(Output{ number, Output::Type::ERROR }));
    }
    else {
        qDebug() << "[EligibilityService] emitting eligibility check result.";
        emit(eligibility(Output{ number, number % 2 == 0 ? Output::Type::CUSTOMER_ELIGIBLE : Output::Type::CUSTOMER_INELIGIBLE }));
    }
}

void EligibilityService::setRewardsService(RewardsService& rewardsService)
{
    if (!_rewardsService)
    {
        //TODO disconnect everything
    }
    _rewardsService = &rewardsService;
   
    connect(this, &EligibilityService::eligibility, _rewardsService, &RewardsService::eligibilityGiven);
}
}
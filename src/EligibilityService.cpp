#include "EligibilityService.h"

namespace services
{

EligibilityService::EligibilityService(QObject* parent) : Service(parent)
{}

EligibilityService::~EligibilityService() {}

void EligibilityService::checkEligibility(const AccountNumber number)
{
    if (number <= 0)
    {
        emit(Output::ERROR);
    }
    else {
        emit(number % 2 == 0 ? Output::CUSTOMER_ELIGIBLE : Output::CUSTOMER_INELIGIBLE);
    }
}
}

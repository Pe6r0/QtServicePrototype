#pragma once
#include <QWidget>
#include <QPointer>

#include "Service.h"

//TODO: Eligibility Service currently in development. For Testing purposes it just replied based on account number parity.
namespace services {
    using AccountNumber = size_t;

    class EligibilityService : public Service {
        Q_OBJECT
    public:
        enum class Output
        {
            CUSTOMER_ELIGIBLE,
            CUSTOMER_INELIGIBLE,
            ERROR
        };

        EligibilityService(QObject* parent = nullptr);

        ~EligibilityService();

    signals:
        void eligibility(Output value);

    public slots:
        void checkEligibility(const AccountNumber number);

    private:
        //QPointer<RewardsService> _service;
    };
    
} // namespace services
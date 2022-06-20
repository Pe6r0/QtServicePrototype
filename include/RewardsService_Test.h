#pragma once
#include <QPointer>
#include <iostream>
#include <QTest>

#include "Comm.h"
#include "RewardsService.h"
#include "EligibilityService.h"

namespace
{
    services::AccountNumber cInvalidNumber = 0;
}

class RewardsService_Test : public QObject {
    Q_OBJECT


    //emulates the behaviour of the caller for rewards requests. In a non test environment this object would follow similar slot/signal pattern as the rewardsService
    void rewardsQuery(const services::AccountNumber number, const std::vector<services::Channel>& channels) 
    {
        QVERIFY(_rewardsService != nullptr);
        QVERIFY(_eligibilityService != nullptr);
        QVERIFY(_data.first == cInvalidNumber);

        connect(_rewardsService, &services::RewardsService::rewardsAvailable, this, [&](services::AccountNumber number, std::vector<services::Reward> results)
            {
                _data = { number, results };
            });

        _rewardsService->rewardsCheck(number, channels);
        QCoreApplication::processEvents();
    }

private slots:
    void init()
    {
        _data = { cInvalidNumber, {} };
        _rewardsService = new services::RewardsService(this);
        _eligibilityService = new services::EligibilityService(this);
    }

    void cleanup()
    {
        delete _rewardsService.data();
    }

    void testDefaultRunningBehaviour()
    { 
        QVERIFY(!_rewardsService->isRunning());
    }

    void testStartStop()
    {
        QVERIFY(!_rewardsService->isRunning());
        _rewardsService->start();
        QVERIFY(_rewardsService->isRunning());
        _rewardsService->stop();
        QVERIFY(!_rewardsService->isRunning());
    }

    void testConnectionToService_noEligibilityService()
    {
        rewardsQuery(249, { services::Channel::KIDS });

        QVERIFY(_data.first == cInvalidNumber);
    }

    void testConnectionToService_testEligibilityServiceNotRunning()
    {
        _rewardsService->start();
        _rewardsService->setEligibityService(*_eligibilityService);
        rewardsQuery(249, { services::Channel::KIDS });
        QVERIFY(_data.first == cInvalidNumber);
    }

    void testConnectionToService_succesfulConnection() 
    {
        const int testNumber = 248;
        _rewardsService->start();
        _eligibilityService->start();
        _rewardsService->setEligibityService(*_eligibilityService);
        rewardsQuery(testNumber, { services::Channel::SPORTS });
        
        QVERIFY(_data.first == testNumber);
        QVERIFY(_data.second == std::vector<services::Reward>{ services::Reward::CHAMPIONS});
    }

    void testConnectionToService_succesfulConnection_unneligible()
    {
        const int testNumber = 241;
        _rewardsService->start();
        _eligibilityService->start();
        _rewardsService->setEligibityService(*_eligibilityService);
        rewardsQuery(testNumber, { services::Channel::SPORTS });

        QVERIFY(_data.first == testNumber);
        QVERIFY(_data.second.empty()); //todo: no pair
    }

    void testConnectionToService_succesfulConnection_badRequest()
    {
        const int testNumber = 0;
        _rewardsService->start();
        _eligibilityService->start();
        _rewardsService->setEligibityService(*_eligibilityService);
        rewardsQuery(testNumber, { services::Channel::SPORTS });

        QVERIFY(_data.first == testNumber);
        QVERIFY(_data.second.empty()); //todo: no pair
    }


private:
    QPointer<services::RewardsService>_rewardsService;
    QPointer<services::EligibilityService>_eligibilityService;
    std::pair<services::AccountNumber, std::vector<services::Reward>> _data{ cInvalidNumber, {} };
};

//#include "RewardsService_Test.moc"

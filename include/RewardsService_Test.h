#pragma once
#include <vector>

#include <QPointer>
#include <iostream>
#include <QTest>

#include "Comm.h"
#include "RewardsService.h"
#include "EligibilityService.h"

class RewardsService_Test : public QObject {
    Q_OBJECT

    /*@brief rewardsQuery emulates the behaviour of the caller for rewards requests.
      In a non test environment this object would follow similar slot/signal pattern as the rewardsService/eligibilityService.*/
    void rewardsQuery(const services::AccountNumber number, const std::vector<services::Channel>& channels) 
    {
        QVERIFY(_rewardsService != nullptr);
        QVERIFY(_eligibilityService != nullptr);
        QVERIFY(_rewardsReply._number == services::cInvalidNumber);

        connect(_rewardsService, &services::RewardsService::rewardsAvailable, this, [&](services::RewardsService::RewardsServiceReply results)
            {
                _rewardsReply = results;
            });

        _rewardsService->rewardsCheck(number, channels);
        QCoreApplication::processEvents();
    }

private slots:
    void init()
    {
        _rewardsReply = services::RewardsService::RewardsServiceReply();
        _rewardsService = new services::RewardsService(this);
        _eligibilityService = new services::EligibilityService(this);
    }

    void cleanup()
    {
        delete _rewardsService.data();
        delete _eligibilityService.data();
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

        QVERIFY(_rewardsReply._number == services::cInvalidNumber);
    }

    void testConnectionToService_testEligibilityServiceNotRunning()
    {
        _rewardsService->start();
        _rewardsService->setEligibityService(*_eligibilityService);
        rewardsQuery(249, { services::Channel::KIDS });

        QVERIFY(_rewardsReply._number == services::cInvalidNumber);
    }

    void testConnectionToService_succesfulConnection() 
    {
        const auto testNumber = 248;
        _rewardsService->start();
        _eligibilityService->start();
        _rewardsService->setEligibityService(*_eligibilityService);
        rewardsQuery(testNumber, { services::Channel::SPORTS });
        
        QVERIFY(_rewardsReply._number == testNumber);
        QVERIFY(_rewardsReply._rewards == std::vector<services::Reward>{ services::Reward::CHAMPIONS});
    }

    void testConnectionToService_succesfulConnectionLarge()
    {
        const auto testNumber = 248;
        _rewardsService->start();
        _eligibilityService->start();
        _rewardsService->setEligibityService(*_eligibilityService);
        rewardsQuery(testNumber, { services::Channel::SPORTS, services::Channel::KIDS, services::Channel::MUSIC });

        QVERIFY(_rewardsReply._number == testNumber);
        QVERIFY(std::find(_rewardsReply._rewards.begin(), _rewardsReply._rewards.end(), services::Reward::CHAMPIONS) != _rewardsReply._rewards.end());
        QVERIFY(std::find(_rewardsReply._rewards.begin(), _rewardsReply._rewards.end(), services::Reward::KARAOKE) != _rewardsReply._rewards.end());
        QVERIFY(std::find(_rewardsReply._rewards.begin(), _rewardsReply._rewards.end(), services::Reward::PIRATES) == _rewardsReply._rewards.end());
    }

    void testConnectionToService_succesfulConnection_unneligible()
    {
        const auto testNumber = 241;
        _rewardsService->start();
        _eligibilityService->start();
        _rewardsService->setEligibityService(*_eligibilityService);
        rewardsQuery(testNumber, { services::Channel::SPORTS });

        QVERIFY(_rewardsReply._number == testNumber);
        QVERIFY(_rewardsReply._rewards.empty());
    }

    void testConnectionToService_succesfulConnection_badRequest()
    {
        const auto testNumber = 0;
        _rewardsService->start();
        _eligibilityService->start();
        _rewardsService->setEligibityService(*_eligibilityService);
        rewardsQuery(testNumber, { services::Channel::SPORTS });

        QVERIFY(_rewardsReply._number == testNumber);
        QVERIFY(_rewardsReply._rewards.empty());
    }

private:
    QPointer<services::RewardsService>_rewardsService;
    QPointer<services::EligibilityService>_eligibilityService;

    services::RewardsService::RewardsServiceReply _rewardsReply;
};

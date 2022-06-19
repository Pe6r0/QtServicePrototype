#pragma once
#include <QJsonDocument>
#include <QFile>
#include <iostream>

#include "../include/ServiceManager.h"
/*
namespace {
    constexpr const char* cConfigFile = "config.json";
}

int main()
{
    std::cerr << "*** Services Starting ***" << std::endl;
    auto file = QFile(cConfigFile);
    if (!file.exists())
    {
        std::cerr << "config.json not present. terminating." << std::endl;
        return EXIT_FAILURE;
    }
    QJsonParseError error;
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    const auto jsonDoc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();

    if (error.error != QJsonParseError::NoError)
    {
        std::cerr << "config.json parsed improperly. [" << error.errorString().toStdString() << error.offset  << "]. Terminating." << std::endl;
        return EXIT_FAILURE;
    }

    services::ServiceManager manager;

    manager.setupServices(jsonDoc);

    //std::cout << jsonDoc.toJson(QJsonDocument::Compact).toStdString() << std::endl;
    return EXIT_SUCCESS;
}*/

#include <QTest>

class RewardsService_Test : public QObject {
    Q_OBJECT
private slots:

    /*

    initTestCase() will be called before the first test function is executed.
    initTestCase_data() will be called to create a global test data table.
    cleanupTestCase() will be called after the last test function was executed.
    init() will be called before each test function is executed.
    cleanup() will be called after every test function.

    */
    void t1() { QVERIFY(true); }

    void t2() { QVERIFY(true); }

    void t4() { QVERIFY(true); }
};

//#include "RewardsService_Test.moc"

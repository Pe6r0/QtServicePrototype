#include "../include/Service_Test.h"
#include "../include/ServiceManager_Test.h"
#include "../include/RewardsService_Test.h"

int main(int argc, char** argv)
{
    int status = 0;

    auto runTest = [&status, argc, argv](QObject&& i)
    {
        status |= QTest::qExec(&i, argc, argv);
    };

    runTest(Service_Test());

    runTest(RewardsService_Test());

    runTest(ServiceManager_Test());

    return status;
}
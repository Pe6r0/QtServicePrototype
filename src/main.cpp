#include "ServiceManager_Test.h"
#include "RewardsService_Test.h"

int main(int argc, char** argv)
{
    auto status = 0;

    const auto runTest = [&status, argc, argv](QObject&& i)
    {
        status |= QTest::qExec(&i, argc, argv);
    };

    runTest(RewardsService_Test());

    runTest(ServiceManager_Test());

    return status;
}
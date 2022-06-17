#pragma once
#include <QObject>
#include <QPointer>

#include "../include/EligibilityService.h"
#include "../include/RewardsService.h"

namespace services {
    class ServiceManager : public QObject {
        Q_OBJECT
    public:
        ServiceManager()
        {

        }

        template <class T>
        void addService(T& service)
        {
            blockSignals(false);
            _running = true;
        };

        void stop()
        {
            _running = false;
            blockSignals(true);
        };

        bool isRunning() { return _running; };

    private:
        QPointer<QObject> _parent{ nullptr };
        bool _running{ true };
    };

} // namespace services
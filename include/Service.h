#pragma once
#include <QObject>

namespace services {
class Service : public QObject {
    Q_OBJECT
public:
    Service(QObject* parent = nullptr) : QObject{ parent }
    {
        blockSignals(true);
    }

    virtual ~Service() {};

    void start() 
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
    bool _running{ false };
};


} // namespace services
#pragma once
#include <QObject>

namespace services {
class Service : public QObject {
    Q_OBJECT
public:
    Service(QObject* parent = nullptr);

    virtual ~Service();

    void start();

    void stop();

    bool isRunning();

private:
    bool _running{ false };
};


} // namespace services
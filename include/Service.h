#pragma once
#include <QObject>

namespace services {
//@brief Abstract class for all services, adds running functionality.
class Service : public QObject {
    Q_OBJECT
public:
    Service(QObject* parent = nullptr);
    Service(const Service& other) = delete;
    Service& operator=(const Service& other) = delete;

    virtual ~Service();

    void start();

    void stop();

    bool isRunning();

private:
    bool _running{ false };
};
} // namespace services
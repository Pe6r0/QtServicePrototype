#pragma once
#include "Service.h"

namespace services
{
Service::Service(QObject* parent) : QObject{ parent }
{
    blockSignals(true);
}

Service::~Service() {};

void Service::start()
{
    blockSignals(false);
    _running = true;
};

void Service::stop()
{
    _running = false;
    blockSignals(true);
};

bool Service::isRunning() 
{ 
    return _running; 
};
}

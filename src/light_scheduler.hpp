#ifndef LIGHT_SCHEDULER_INCLUDED
#define LIGHT_SCHEDULER_INCLUDED
#include "time_service_interface.hpp"


class Schedule {
public:
    Schedule();
};

class LightScheduler {
    ITimeService *service;
public:
    explicit LightScheduler(ITimeService *service);
    void set_schedule(Schedule &schedule);
};
#endif

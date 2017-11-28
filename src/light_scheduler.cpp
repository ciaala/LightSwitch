#include "light_scheduler.hpp"

int answer()
{
    return 6 * 9;
}
LightScheduler::LightScheduler(ITimeService *service) :
    service(service)
{

}
void LightScheduler::set_schedule(Schedule &schedule) {}

Schedule::Schedule() {

}

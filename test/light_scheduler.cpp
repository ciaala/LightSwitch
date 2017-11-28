#include "light_scheduler.hpp"
#include <gmock/gmock.h>
#include "time_service_interface.hpp"

using namespace ::testing;

class MockSchedule : public Schedule {

};

class MockTimeService : public ITimeService {
public:
    // MOCK_METHOD0(current_time,  time_t(void) const);

    MOCK_METHOD2(set_periodic_alarm, callback_handler(
            std::chrono::minutes,
            ITimeService::wakeup_callback));

    // MOCK_METHOD1(unset_periodic_alarm, void(callback_handler));

};

namespace {

    TEST(LIGHT_SCHEDULER, CHECK_LIGHT_SCHEDULER_REGISTER_TO_TIMESERVICE) {
        MockTimeService timeService;

        LightScheduler scheduler(&timeService);
        MockSchedule mockSchedule;
        scheduler.set_schedule(mockSchedule);
        EXPECT_CALL(timeService,
                    set_periodic_alarm(
                            _, _
                    ))
                .Times(1);

    }


    /*

        Schedule schedule;
        lightScheduler.set_schedule(schedule);

        EXPECT_ANY_THROW();
    */
}



#ifndef MICROSERVICE_H
#define MICROSERVICE_H

#include "Alarm.h"
#include "Clock.h"

class Microservice {
public:
    Microservice(Clock& clock, Alarm& alarm) : clock(clock), alarm(alarm) {}

    bool isAlarmTime() {
        return clock.hours == alarm.alarmHours && clock.minutes == alarm.alarmMinutes;
    }

private:
    Clock& clock;
    Alarm& alarm;
};

#endif // MICROSERVICE_H

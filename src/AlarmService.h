#ifndef ALARM_SERVICE_H
#define ALARM_SERVICE_H

#include "Alarm.h"
#include "Microservice.h"

class AlarmService : public Microservice {
private:
    Alarm alarm;

public:
    void setAlarm(int hours, int minutes) {
        alarm.setAlarm(hours, minutes);
    }

    bool checkAlarm(int hours, int minutes, int seconds) {
        return (alarm.alarmHours == hours &&
                alarm.alarmMinutes == minutes &&
                seconds == 0);
    }

    void displayAlarm() const {
        alarm.displayAlarm();
    }

    void execute() override {
        std::cout << "AlarmService: Executando tarefas de alarme..." << std::endl;
        displayAlarm();
    }
};

#endif // ALARM_SERVICE_H

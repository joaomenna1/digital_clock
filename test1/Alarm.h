#ifndef ALARM_H
#define ALARM_H

#include <iostream>

class Alarm {
public:
    int alarmHours = 0;
    int alarmMinutes = 0;

    void setAlarm(int h, int m) {
        alarmHours = h % 24;     
        alarmMinutes = m % 60;     
    }

    void displayAlarm() const {
        std::cout << "Despertador - Horas: " << alarmHours
                  << " Minutos: " << alarmMinutes << std::endl;
    }
};

#endif // ALARM_H

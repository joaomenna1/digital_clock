#ifndef ALARM_H
#define ALARM_H

#include <iostream>

class Alarm {
public:
    int alarmHours = 0;
    int alarmMinutes = 0;

    void setAlarm(int h, int m) {
        alarmHours = h % 24;       // Garante que as horas estejam no intervalo
        alarmMinutes = m % 60;     // Garante que os minutos estejam no intervalo
    }

    void displayAlarm() const {
        std::cout << "Despertador - Horas: " << alarmHours << " Minutos: " << alarmMinutes << std::endl;
    }
};

#endif // ALARM_H
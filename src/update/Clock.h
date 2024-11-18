
#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>

class Clock {
public:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    void increment() {
        seconds++;
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes >= 60) {
            minutes = 0;
            hours++;
        }
        if (hours >= 24) {
            hours = 0;
        }
    }

    void displayTime() const {
        std::cout << "Relógio - Horas: " << hours << " Minutos: " << minutes << " Segundos: " << seconds << std::endl;
    }
};

#endif // CLOCK_H

#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <thread> 
#include <chrono>  

class Clock {
public:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    
    void setAlarm(int h, int m) {
        hours = h % 24;
        minutes = m % 60;
        seconds = 0; 
    }

   
    void decrement() {
        if (seconds > 0) {
            seconds--;
        } else if (minutes > 0) {
            seconds = 59;
            minutes--;
        } else if (hours > 0) {
            minutes = 59;
            seconds = 59;
            hours--;
        }
    }

   
    void displayTime() const {
        std::cout << "Relógio - Horas: " << hours 
                  << " Minutos: " << minutes 
                  << " Segundos: " << seconds << std::endl;
    }

  
    void waitOneSecond() const {
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
    }
};

#endif // CLOCK_H

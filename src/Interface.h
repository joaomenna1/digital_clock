#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <thread>
#include <chrono>
#include "Clock.h"
#include "Alarm.h"
#include "Compare.h" 

class Interface {
public:
    Clock clock;
    Alarm alarm;
    Compare comparator{4}; 
    bool alarmTriggered = false;
    
 void run() {
    bool showClock = true;
    char input;

    while (true) {
        if (!alarmTriggered) {
        
            std::this_thread::sleep_for(std::chrono::seconds(60));
            clock.increment();
            
            
            if (showClock) {
                clock.displayTime();
            } else {
                alarm.displayAlarm();
            }

            
            if (checkAlarm()) {
                std::cout << "Alarme tocando! Hora de acordar!" << std::endl;
                alarmTriggered = true;
            }

        
            std::cout << "Pressione 'h' para incrementar horas do despertador, 'm' para incrementar minutos, 't' para alternar exibição entre relógio e despertador." << std::endl;
            std::cin >> input;

            switch (input) {
                case 'h':
                    alarm.alarmHours = (alarm.alarmHours + 1) % 24;
                    break;
                case 'm':
                    alarm.alarmMinutes = (alarm.alarmMinutes + 1) % 60;
                    break;
                case 't':
                    showClock = !showClock;
                    break;
                default:
                    break;
            }
        } else {
            std::cout << "Alarme tocando! Hora de acordar!" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}


    bool checkAlarm() {
    return clock.hours == alarm.alarmHours && clock.minutes == alarm.alarmMinutes;
}

};

#endif // INTERFACE_H

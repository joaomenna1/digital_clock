
#ifndef LOGIC_BUILDER_H
#define LOGIC_BUILDER_H

#include "Clock.h"
#include "Alarm.h"
#include "Microservice.h"
#include <thread>
#include <chrono>

class LogicBuilder {
public:
    Clock clock;
    Alarm alarm;
    Microservice service;

    LogicBuilder() : service(clock, alarm) {}

    void run() {
        bool showClock = true;
        bool alarmTriggered = false;
        char input;

        while (true) {
            if (!alarmTriggered) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                clock.increment();

                if (showClock) {
                    clock.displayTime();
                } else {
                    alarm.displayAlarm();
                }

                if (service.isAlarmTime()) {
                    std::cout << "Alarme tocando! Hora de acordar!" << std::endl;
                    alarmTriggered = true;
                }

                std::cout << "Pressione 'h' para incrementar horas, 'm' para minutos, 't' para alternar exibição." << std::endl;
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
};

#endif // LOGIC_BUILDER_H

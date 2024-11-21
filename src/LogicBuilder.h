#ifndef LOGIC_BUILDER_H
#define LOGIC_BUILDER_H

#include "AlarmService.h"
#include "ClockService.h"
#include "LogicService.h"

class LogicBuilder {
private:
    AlarmService alarmService;
    ClockService clockService;
    LogicService logicService;
    bool isRunning = false; // Flag para controlar o modo relógio

public:
    void setAlarm(int hours, int minutes) {
        alarmService.setAlarm(hours, minutes);
        clockService.setClock(hours, minutes);
    }

    void startCountdown() {
        std::cout << "Iniciando contagem..." << std::endl;

        while (true) {
            clockService.displayClock();
            clockService.decrement();
            clockService.getClock().waitOneSecond();

            if (alarmService.checkAlarm(clockService.getHours(),
                                        clockService.getMinutes(),
                                        clockService.getSeconds())) {
                std::cout << "Alarme tocando! Hora de acordar!" << std::endl;
                break;
            }

            if (clockService.getHours() == 0 &&
                clockService.getMinutes() == 0 &&
                clockService.getSeconds() == 0) {
                std::cout << "Alarme acionado!!!." << std::endl;
                break;
            }
        }
    }

    void runClock() {
        isRunning = true; // Inicia o modo relógio
        while (isRunning) {
            clockService.increment();
            clockService.displayClock();
            clockService.getClock().waitOneSecond();
        }
    }

    void stopClockMode() {
        isRunning = false; // Para o modo relógio
    }
};

#endif // LOGIC_BUILDER_H

#ifndef CLOCK_SERVICE_H
#define CLOCK_SERVICE_H

#include "Clock.h"
#include "Microservice.h"

class ClockService : public Microservice {
private:
    Clock clock;

public:
    void setClock(int hours, int minutes) {
        clock.hours = hours % 24;
        clock.minutes = minutes % 60;
        clock.seconds = 0;
    }

    void decrement() {
        clock.decrement();
    }

    void increment() {
        clock.increment();
    }

    void displayClock() const {
        clock.displayTime();
    }

    Clock& getClock() { // Para acessar métodos como waitOneSecond
        return clock;
    }

    int getHours() const { return clock.hours; }
    int getMinutes() const { return clock.minutes; }
    int getSeconds() const { return clock.seconds; }

    void execute() override {
        std::cout << "ClockService: Atualizando relógio..." << std::endl;
        decrement();
        displayClock();
    }
};

#endif // CLOCK_SERVICE_H

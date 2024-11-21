#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <thread>
#include <chrono>

void clearConsole() {
#ifdef _WIN32
    system("cls"); // Limpa a tela no Windows
#else
    system("clear"); // Limpa a tela em sistemas Unix/Linux/Mac
#endif
}

class Clock {
public:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

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

    void increment() {
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
            if (minutes == 60) {
                minutes = 0;
                hours++;
                if (hours == 24) {
                    hours = 0;
                }
            }
        }
    }

    void displayTime() const {
        clearConsole();
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
                  << (minutes < 10 ? "0" : "") << minutes << ":"
                  << (seconds < 10 ? "0" : "") << seconds << std::endl;
    }

    void waitOneSecond() const {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
};

#endif // CLOCK_H

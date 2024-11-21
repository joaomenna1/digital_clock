#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <thread> // Para std::this_thread::sleep_for
#include <chrono> // Para std::chrono::seconds
#include "Clock.h"
#include "Alarm.h"

class Interface {
public:
    Clock clock;
    Alarm alarm;
    bool alarmTriggered = false;

    void run() {
        char input;

        while (true) {
            std::cout << "Pressione 's' para configurar o modo despertador (horas e minutos)." << std::endl;
            std::cin >> input;

            if (input == 's') {
                int h, m;
                std::cout << "Digite as horas: ";
                std::cin >> h;
                std::cout << "Digite os minutos: ";
                std::cin >> m;
                // Sincroniza o relógio com o alarme
                alarm.setAlarm(h, m);
                clock.setAlarm(h, m); 
                // Inicia a contagem regressiva
                startCountdown();    
            }
        }
    }

    void startCountdown() {
        std::cout << "Iniciando contagem..." << std::endl;

        
        while (clock.hours > 0 || clock.minutes > 0 || clock.seconds > 0) {
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Pausa por 1 segundo
            clock.decrement();    // Decrementa o tempo
            clock.displayTime();  // Exibe o tempo restante
        }

        // Quando atingir 00:00:00, o alarme toca
        std::cout << "Alarme tocando! Alarme acionado!" << std::endl;
        alarmTriggered = true; 
    }
};

#endif // INTERFACE_H

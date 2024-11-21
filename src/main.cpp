#include "LogicBuilder.h"
#include <iostream>

int main() {
    LogicBuilder logicBuilder;
    char option;

    while (true) {
        std::cout << "Escolha uma opçao:\n";
        std::cout << "[r] - Modo Relogio\n";
        std::cout << "[s] - Modo Despertador\n";
        std::cout << "[q] - Sair\n";
        std::cout << "Opção: ";
        std::cin >> option;

        if (option == 'r') {
            std::cout << "Modo relogio ativado. Pressione 'x' para sair do modo relógio.\n";
            std::thread clockThread([&logicBuilder]() { logicBuilder.runClock(); });

            // Verifica entrada para sair do modo relógio
            char exitOption;
            do {
                std::cin >> exitOption;
            } while (exitOption != 'x');

            logicBuilder.stopClockMode(); // Para o modo relógio
            clockThread.join();           // Aguarda o encerramento do thread
        } else if (option == 's') {
            int hours, minutes;
            std::cout << "Digite as horas para o despertador: ";
            std::cin >> hours;
            std::cout << "Digite os minutos para o despertador: ";
            std::cin >> minutes;

            logicBuilder.setAlarm(hours, minutes);
            logicBuilder.startCountdown();
        } else if (option == 'q') {
            std::cout << "Saindo do programa. Até logo!" << std::endl;
            break;
        } else {
            std::cout << "Opção invalida! Tente novamente.\n";
        }
    }

    return 0;
}

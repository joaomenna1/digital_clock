#include "Interface.h"

int main() {
    Interface interface;
    int alarmHour, alarmMinute;

    std::cout << "Configuração do Despertador" << std::endl;
    std::cout << "Digite a hora para o alarme: ";
    std::cin >> alarmHour;
    std::cout << "Digite os minutos para o alarme: ";
    std::cin >> alarmMinute;

    interface.alarm.setAlarm(alarmHour, alarmMinute); // Configura o alarme
    interface.run(); // Inicia a simulação

    return 0;
}

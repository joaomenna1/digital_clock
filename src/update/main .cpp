
#include "LogicBuilder.h"

int main() {
    LogicBuilder logic;
    int alarmHour, alarmMinute;

    std::cout << "Configuração do Despertador" << std::endl;
    std::cout << "Digite a hora para o alarme: ";
    std::cin >> alarmHour;
    std::cout << "Digite os minutos para o alarme: ";
    std::cin >> alarmMinute;

    logic.alarm.setAlarm(alarmHour, alarmMinute);
    logic.run();

    return 0;
}

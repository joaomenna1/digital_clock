#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <thread>
#include <chrono>
#include "Clock.h"
#include "Alarm.h"
#include "Compare.h"
#include "ArithmeticFlow.h"

class Interface {
public:
	Clock clock;
	Alarm alarm;
	Compare comparator;                 // Comparador de magnitude
	ArithmeticFlow flowSeconds{59};     // Fluxo para segundos
	ArithmeticFlow flowMinutes{59};     // Fluxo para minutos
	ArithmeticFlow flowHours{23};       // Fluxo para horas

	Interface() : comparator(8) {} // Configura 8 bits como exemplo

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

				alarm.setAlarm(h, m);
				clock.setAlarm(h, m); // Sincroniza o relC3gio com o alarme
				startCountdown();     // Inicia a contagem regressiva
			}
		}
	}

	void startCountdown() {
		// Configura os segundos iniciais corretamente
		if (clock.seconds == 0 && clock.minutes > 0) {
			clock.seconds = 59;
			clock.minutes--;
		}

		std::cout << "Iniciando contagem regressiva..." << std::endl;

		while (true) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			decrementClock();
			clock.displayTime();

			if (checkAlarm()) {
				std::cout << "Alarme tocando! Hora de acordar!" << std::endl;
				break;
			}

			// Verifica se o relC3gio chegou a zero absoluto
			if (clock.hours == 0 && clock.minutes == 0 && clock.seconds == 0) {
				std::cout << "alarme acionado!!" << std::endl;
				break;
			}
		}
	}

	void decrementClock() {
		// Decrementar segundos
		flowSeconds.setDataA(clock.seconds);
		flowSeconds.setDataB(1);
		flowSeconds.setOperationMode(operationType::sub);
		flowSeconds.doFlow();
		clock.seconds = flowSeconds.getResult();

		if (clock.seconds == 59) { // Quando segundos passam de 0 para 59, decrementa minutos
			flowMinutes.setDataA(clock.minutes);
			flowMinutes.setDataB(1);
			flowMinutes.setOperationMode(operationType::sub);
			flowMinutes.doFlow();
			clock.minutes = flowMinutes.getResult();

			if (clock.minutes == 59) { // Quando minutos passam de 0 para 59, decrementa horas
				flowHours.setDataA(clock.hours);
				flowHours.setDataB(1);
				flowHours.setOperationMode(operationType::sub);
				flowHours.doFlow();
				clock.hours = flowHours.getResult();
			}
		}
	}

	bool checkAlarm() {
		// ComparaC'C#o de horas
		comparator.setDataA(clock.hours);
		comparator.setDataB(alarm.alarmHours);
		comparator.doArithmetic();

		if (!comparator.getEqualOut())
			return false;

		// ComparaC'C#o de minutos
		comparator.setDataA(clock.minutes);
		comparator.setDataB(alarm.alarmMinutes);
		comparator.doArithmetic();

		if (!comparator.getEqualOut())
			return false;

		// ComparaC'C#o de segundos
		comparator.setDataA(clock.seconds);
		comparator.setDataB(0);
		comparator.doArithmetic();

		return comparator.getEqualOut();
	}
};

#endif // INTERFACE_H

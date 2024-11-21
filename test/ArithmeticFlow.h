#ifndef ARITHMETIC_FLOW_H
#define ARITHMETIC_FLOW_H

#include "Flow.h"

class ArithmeticFlow : public Flow {
public:
    ArithmeticFlow(int maxData = 59) : Flow(8) { // Define o máximo de dados esperado
        maximumData = maxData;
    }

    void doFlow() override {
        if (operationMode == operationType::add) {
            result = dataA + dataB;
        } else if (operationMode == operationType::sub) {
            result = dataA - dataB;
        }

        // Ajusta o resultado para o intervalo permitido
        if (result < 0) {
            result += (maximumData + 1);
        } else if (result > maximumData) {
            result %= (maximumData + 1);
        }
    }

    bool isTheDataValid(int data) override {
        return (data >= 0 && data <= maximumData);
    }

    void doArithmetic() override {
        doFlow();
    }
};

#endif // ARITHMETIC_FLOW_H

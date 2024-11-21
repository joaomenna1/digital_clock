#ifndef FLOW_H
#define FLOW_H

#include <math.h>

enum class operationType : int {
    add = 0,
    sub = 1
};

class Flow {
public:
    Flow(int dataBitSize = 4) {
        enable = 1;
        dataA = 0;
        dataB = 0;
        operationMode = operationType::add;
        Flow::dataBitSize = dataBitSize;
        maximumData = pow(2, dataBitSize) - 1;
        result = 0;
    }

    void setEnable(int enable) {
        Flow::enable = (enable == 1) ? 1 : 0;
    }

    void setDataA(int dataA) {
        Flow::dataA = isTheDataValid(dataA) ? dataA : 0;
    }

    void setDataB(int dataB) {
        Flow::dataB = isTheDataValid(dataB) ? dataB : 0;
    }

    void setOperationMode(operationType operation) {
        operationMode = operation;
    }

    virtual void doFlow() = 0;

    int getResult() {
        return result;
    }

protected:
    virtual bool isTheDataValid(int data) = 0;

    int enable;
    unsigned int dataA, dataB;
    operationType operationMode;
    unsigned int result;
    int dataBitSize;
    int maximumData;
};

#endif // FLOW_H

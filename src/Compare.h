#ifndef COMPARE_H
#define COMPARE_H

#include "Flow.h"

class Compare : public Flow {
public:
    Compare(int dataBitSize = 4) : Flow(dataBitSize) {}

    void doFlow() override {}

    void doArithmetic() {
        if (dataA > dataB) {
            gleOut = 0b100;
        } else if (dataA < dataB) {
            gleOut = 0b010;
        } else {
            gleOut = 0b001;
        }
    }

    int getEqualOut() {
        return gleOut & 0b001;
    }

private:
    bool isTheDataValid(int data) override {
        return (data >= 0 && data <= maximumData);
    }

    int gleOut = 0;
};

#endif // COMPARE_H

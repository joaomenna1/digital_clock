#ifndef LOGIC_SERVICE_H
#define LOGIC_SERVICE_H

#include "Flow.h"
#include "Compare.h"
#include "Microservice.h"

class LogicService : public Microservice {
private:
    Compare comparator;

public:
    LogicService() : comparator(8) {}

    bool compareValues(int a, int b) {
        comparator.setDataA(a);
        comparator.setDataB(b);
        comparator.doArithmetic();
        return comparator.getEqualOut();
    }

    void execute() override {
        std::cout << "LogicService: Executando operações de comparação..." << std::endl;
    }
};

#endif // LOGIC_SERVICE_H

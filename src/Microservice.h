#ifndef MICROSERVICE_H
#define MICROSERVICE_H

class Microservice {
public:
    virtual void execute() = 0; // Método abstrato para execução de tarefas
    virtual ~Microservice() {}
};

#endif // MICROSERVICE_H

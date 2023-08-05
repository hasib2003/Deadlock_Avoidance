//
// Created by hasib on 8/4/23.
//

#ifndef LAB11_12_BANKER_H
#define LAB11_12_BANKER_H

#include "process.h"
#include "resource.h"

class banker {
private:
    int totalProcess;
    int totalResources;
    process * processArray;
    resource * resourceArray;

    int * remainingNeed;
    int * remainingResource;

public:
    banker();
    ~banker();

    void inputProcesses();
    void inputResources();
    void printSummary();

    void schedulize();
    void freeUpAllResources(int);

    bool needBeSatisfied(int);



};


#endif //LAB11_12_BANKER_H

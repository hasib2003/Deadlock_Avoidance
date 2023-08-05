//
// Created by hasib on 8/4/23.
//

#include "banker.h"


int main(){

    banker bankerSimulator;
    bankerSimulator.inputProcesses();
    bankerSimulator.printSummary();
    bankerSimulator.schedulize();

    return 0;
}
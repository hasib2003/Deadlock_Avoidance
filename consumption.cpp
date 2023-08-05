//
// Created by hasib on 8/4/23.
//

#include "consumption.h"
#include <iostream>
consumption ::consumption() {
    resourceIdx = -2;
    maxInstNeed = 0;
    instHeld = 0;
    remainingInst = 0;
}

bool consumption ::holdInstance(int val) {
    if(val+instHeld > maxInstNeed) {

        std::cout<<"Value + Already held "<<val+instHeld <<" excedes the maxmimum instances needed"<<std::endl;
        return false;
    }

    instHeld += val;
    remainingInst = maxInstNeed - val;

    return true;
}
bool consumption ::setMaxInstNeed(int val) {
    maxInstNeed = val;
    remainingInst = val;
    instHeld = 0;
}
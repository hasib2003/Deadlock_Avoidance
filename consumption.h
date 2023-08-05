//
// Created by hasib on 8/4/23.
//

#ifndef LAB11_12_CONSUMPTION_H
#define LAB11_12_CONSUMPTION_H


#include "resource.h"
class consumption {
    public:
        // index of the resource in resourceArray in banker class instance
        int resourceIdx;

        int maxInstNeed;
        int instHeld;
        int remainingInst;

        consumption();

        bool holdInstance(int);
        bool setMaxInstNeed(int);


};


#endif //LAB11_12_CONSUMPTION_H

//
// Created by hasib on 8/4/23.
//

#ifndef LAB11_12_PROCESS_H
#define LAB11_12_PROCESS_H
#include "consumption.h"

class process {
public:
    int pId;
    consumption * consumptionArray; // contains the information about the resources
    // help as well as the max need and remaining need;

    process();

};


#endif //LAB11_12_PROCESS_H

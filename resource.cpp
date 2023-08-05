//
// Created by hasib on 8/4/23.
//

#include "resource.h"
#include <iostream>
resource ::resource() {
    totalInstances = 0;
    allocatedInstances = 0;
    remainingInstances = 0;
    resourceId = -1;
}

bool resource ::allocateInst( int value) {

    if(remainingInstances - value < 0) {
//        std::cout<<"inside main array "<<std::endl;
        std::cout<<"Can not allocate "<<value <<" out of "<< remainingInstances<<std::endl;
//        std::cout<<"remaining "<<remainingInstances<<" total "<<totalInstances<<" allocated "<<allocatedInstances<<std::endl;
        return false;
    }

    remainingInstances -= value;
    allocatedInstances += value;

    return true;

}

bool resource ::freeInst(int value) {
    if (value + remainingInstances > totalInstances){
        std::cout<<"Can not reclaim "<<value <<". Total Instances must be less than "<< totalInstances<<std::endl;
        return false;

    }

    remainingInstances += value;
    allocatedInstances -= value;

    return true;
}
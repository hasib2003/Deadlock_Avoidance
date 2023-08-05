//
// Created by hasib on 8/4/23.
//

#ifndef LAB11_12_RESOURCE_H
#define LAB11_12_RESOURCE_H


class resource {
    public:
        int resourceId;
        int totalInstances;
        int allocatedInstances;
        int remainingInstances;

        // shall be called when a resource has to
        // be reclaimed from a process

        bool freeInst(int);

        // shall be called when a resource has to
        // be allocated to a process

        bool allocateInst(int);

        resource();



};


#endif //LAB11_12_RESOURCE_H

//
// Created by hasib on 8/4/23.
//

#include "banker.h"
#include <iostream>
banker::banker() {
    std::cout<<"** welcome to the bankers algorithim **"<<std::endl;
    totalProcess = 0;
    processArray = nullptr;
    resourceArray  = nullptr;

}

void banker::inputProcesses() {
    std::cout<<"Enter total number of processes "<<std::endl;
    std::cin>>totalProcess;
    while (totalProcess < 1){
        std::cout<<"Invalid Input "<<std::endl;
        std::cout<<"Enter total number of processes "<<std::endl;
        std::cin>>totalProcess;
    }

    processArray = new process[totalProcess];

    std::cout<<"Processes created successfully"<<std::endl;

    inputResources();

    std::cout<<" please describe the allocated resources "<<std::endl;

    for (int i =0 ;i<totalProcess;i++){
        processArray[i].pId = i;

        // assigning every process the consumption array
        processArray[i].consumptionArray = new consumption[totalResources];


        // here we are directly manipulating the consumption
        // array not the original resource array


        int temp = 0;

        std::cout<<"Process Id "<<i<<std::endl;
        for (int j =0 ;j<totalResources;j++){

            processArray[i].consumptionArray[j].resourceIdx = j;

            std::cout<<"Maximum Instances of resource Id "<<j << " required for this process ";
            std::cin>>temp;


            while (temp < 0){
                std::cout<<"Invalid Input "<<std::endl;
                std::cout<<"Maximum Instances of resource Id "<<j << " required for this process ";
                std::cin>>temp;

            }
            processArray[i].consumptionArray[j].setMaxInstNeed(temp);
            temp = 0;


            std::cout<<"Instance of resource Id "<<j << " allocated to this process ";
            std::cin>>temp;

            // here we need to do basically two things
            // free an instance from the main resource array
            // call holdinstance() function in the consumption array


            while (!(temp >= 0 && resourceArray[j].allocateInst(temp) && processArray[i].consumptionArray[j].holdInstance(temp) )){

                // this while loop will break only if , instances requested to be freed
                // are > 0, available among total and holdable by the target process

                std::cout<<"Invalid Input "<<std::endl;
                std::cout<<"Instance of resource Id "<<j << " allocated to this process ";
                std::cin>>temp;
            }

        }
    }

}

void banker::inputResources() {
    std::cout<<"Enter total number of resources "<<std::endl;
    std::cin>>totalResources;
    while (totalResources < 1){
        std::cout<<"Invalid Input "<<std::endl;
        std::cout<<"Enter total number of resources "<<std::endl;
        std::cin>>totalResources;
    }

    resourceArray = new resource[totalResources];
    for (int i =0 ;i<totalResources;i++){
        resourceArray[i].resourceId = i;
        std::cout<<"Enter total instances of resource with Id "<<i<<" ";
        std::cin>>resourceArray[i].totalInstances;

        while (resourceArray[i].totalInstances < 1){
            std::cout<<"Invalid Input "<<std::endl;
            std::cout<<"Enter total instances of resource with Id "<<i<<" ";
            std::cin>>resourceArray[i].totalInstances;
        }
        resourceArray[i].remainingInstances = resourceArray[i].totalInstances;

    }

}

void banker::printSummary() {
    // this function shows how many and which
    // resources are held by a particular
    // process
    // and total resources allocated and available
    // at the moment
    remainingResource = new int[totalResources];
    remainingNeed = new int[totalProcess * totalResources];

    for(int i=0; i<totalResources;i++){
        remainingResource[i] = resourceArray[i].remainingInstances ;
    }

    for(int i=0; i<totalProcess;i++){
        for (int j=0;j<totalResources;j++){
            remainingNeed[j+(totalResources * i)] = processArray[i].consumptionArray[j].remainingInst ;
        }
    }


}

bool banker :: needBeSatisfied( int targetProcessIdx){
    bool allSatisfied = true;
    int startIdx = targetProcessIdx*totalResources;
    for(int i = startIdx;i<startIdx+totalResources;i++){
        allSatisfied = remainingResource[startIdx % totalResources] >= remainingNeed[i] && allSatisfied;

    }
    return allSatisfied;


}

void banker ::freeUpAllResources(int processId) {
    for(int i =0;i< this->totalResources;i++){
       remainingResource[i] += processArray[processId].consumptionArray[i].instHeld;
    }
    std::cout<<" available resources ";
    for (int i =0;i<totalResources;i++){
        std::cout<<remainingResource[i]<<" ";
    }
    std::cout<<std::endl;
}

void banker ::schedulize() {
    int i=0;
    int count = 0;

    while (count<totalProcess && !(count == 0 && i==totalProcess -1 ) ){
        if(processArray[i%totalProcess].pId > -1 && needBeSatisfied(i%totalProcess)){
                std::cout<<"resources assigned to process with id "<<processArray[i%totalProcess].pId<<std::endl;
                freeUpAllResources(i%totalProcess);
                processArray[i%totalProcess].pId  = -9; // means it is removed
           count++;
            }
        i++;

    }
    if(count == 0){
        std::cout<<"** deadlock due to circular wait **"<<std::endl;
        std::cout<<"** can not schedule **"<<std::endl;
        std::cout<<"** happy programming **"<<std::endl;
    }
}

banker::~banker() {
    delete[] remainingResource;
    delete[] remainingNeed;
    delete processArray;
    delete resourceArray;
}
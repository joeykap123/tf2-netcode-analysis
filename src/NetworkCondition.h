#ifndef NETWORKCONDITION_H
#define NETWORKCONDITION_H

struct NetworkCondition 
{
    float latencyMs;
    float jitterMs;
    float packetLoss;


    // Constructor
    NetworkCondition(float latencyMs, float jitterMs, float packetLoss) : latencyMs(0), jitterMs(0), packetLoss(0){}; 

};

// maybe have a randomize method???

#endif NETWORKCONDITION_H

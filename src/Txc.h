#ifndef TXC_H_
#define TXC_H_

#include <omnetpp.h>
#include <string.h>

class Txc : public cSimpleModule {
public:
    int counter;
    Txc();
    virtual ~Txc();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif /* TXC_H_ */

#ifndef TXC_H_
#define TXC_H_

#include <omnetpp.h>
#include <string.h>

class Txc : public cSimpleModule {
public:
    int counter;
    simtime_t delay;
    cMessage *tictocmsg;
    cMessage *event;
    Txc();
    virtual ~Txc();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif /* TXC_H_ */

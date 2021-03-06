#ifndef TXC3_H_
#define TXC3_H_

#include<omnetpp.h>
#include<string.h>
#include<TicTocMsg13_m.h>

/**
 * Idea - Message is transmitted between randomly until it arrives at
 * a particular destination where it is deleted.
 */

class Txc3: public cSimpleModule {
public:
    Txc3();
    virtual ~Txc3();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void forwardMessage(cMessage *msg);
    virtual TicTocMsg13 *generateMessage();
};

#endif /* TXC3_H_ */

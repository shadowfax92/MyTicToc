#ifndef TXC3_H_
#define TXC3_H_

#include<omnetpp.h>
#include<string.h>

/**
 * Idea - Message is transmitted between randomly until it arrives at
 * a particular destination where it is deleted.
 */

namespace TicToc3 {

class Txc3: public cSimpleModule {
public:
    Txc3();
    virtual ~Txc3();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void forwardMessage(cMessage *msg);
};

} /* namespace TicToc3 */
#endif /* TXC3_H_ */

#ifndef TXC3_H_
#define TXC3_H_

#include<omnetpp.h>
#include<string.h>

namespace TicToc3 {

class Txc3: public cSimpleModule {
public:
    Txc3();
    virtual ~Txc3();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

} /* namespace TicToc3 */
#endif /* TXC3_H_ */

#include "Txc3.h"

namespace TicToc3 {

Txc3::Txc3() {
    // TODO Auto-generated constructor stub

}

Txc3::~Txc3() {
    // TODO Auto-generated destructor stub
}

void Txc3::initialize()
{
    if(getIndex()==0)
    {
        EV << "message generated";
        cMessage *msg=new cMessage("ticmsg");
        scheduleAt(0.0,msg);
    }
}
void Txc3::handleMessage(cMessage *msg)
{
    //when message arrives at destination 3 then message has arrived
    if(getIndex()==3)
    {
        EV<< "message arrived at the destination 3";
        delete msg;
    }
    else
    {
        forwardMessage(msg);
    }
}
void Txc3::forwardMessage(cMessage *msg)
{
    int n=gateSize("out");
    //selecting a random number between 0 to n-1. Not for each node the gate size might vary.
    int k=intuniform(0,n-1);
    EV << "forwarding on port k="<<k<<" at node="<<getIndex();
    send(msg,"out",k);
}

} /* namespace TicToc3 */

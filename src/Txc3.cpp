#include "Txc3.h"
#include "TicTocMsg13_m.h"

Define_Module(Txc3);
Txc3::Txc3() {
}

Txc3::~Txc3() {
}
TicTocMsg13 Txc3::generateMessage() {
    int src = getIndex();
    int n = size();
    int dest = intuniform(0, n - 1);
    if (src == dest) {
        dest++;
    }
    char *msg_name;
    sprintf(msg_name, "tictoc message src=%d destination=%d", src, dest);
    TicTocMsg13 *msg = new TicTocMsg13(msg_name);
    msg->setSource(src);
    msg->setDestination(dest);
    msg->setHopcount(0);

    return msg;
}
void Txc3::initialize() {

    if (getIndex() == 0) {
        EV << "message generated";
        cMessage *msg = new cMessage("ticmsg");
        scheduleAt(0.0, msg);
    }
}
void Txc3::handleMessage(cMessage *msg) {
    //when message arrives at destination 3 then message has arrived
    if (getIndex() == 3) {
        EV << "message arrived at the destination 3";
        bubble("message arrived at destination 3");
        delete msg;
    } else {
        forwardMessage(msg);
    }
}
void Txc3::forwardMessage(cMessage *msg) {
    int n = gateSize("out");
    //selecting a random number between 0 to n-1. Not for each node the gate size might vary.
    int k = intuniform(0, n - 1);
    //bubble("");
    EV << "forwarding on port k=" << k << " at node=" << getIndex();
    send(msg, "out", k);
}

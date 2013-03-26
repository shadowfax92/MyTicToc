#include "Txc3.h"

Define_Module(Txc3);
Txc3::Txc3() {
}

Txc3::~Txc3() {
}
void Txc3::initialize() {

    if (getIndex() == 0) {
        EV << "message generated";
        TicTocMsg13 *msg = generateMessage();
        scheduleAt(0.0, msg);
    }
}

TicTocMsg13 *Txc3::generateMessage() {
    int src = getIndex();
    int n = size();
    int dest = intuniform(0, n - 1);
    if (src == dest) {
        dest++;
    }
    char msg_name[30];
    sprintf(msg_name, "tictoc message src=%d destination=%d", src, dest);
    TicTocMsg13 *msg = new TicTocMsg13(msg_name);
    msg->setSource(src);
    msg->setDestination(dest);
    //msg->setHopCount(0);

    return msg;
}

void Txc3::handleMessage(cMessage *msg) {
    //cast the message
    TicTocMsg13 *casted_msg=check_and_cast<TicTocMsg13 *>(msg);

    //when message arrives at destination 3 then message has arrived
    if (casted_msg->getDestination()==getIndex()) {
        char printing_msg[50];
        sprintf(printing_msg,"message arrived at destination=%d and hopcount",getIndex());
        EV <<printing_msg;
        bubble(printing_msg);
        delete msg;
    } else {
        forwardMessage(msg);
    }
}
void Txc3::forwardMessage(cMessage *msg) {
    //increment hopcount
    TicTocMsg13 *casted_msg=check_and_cast<TicTocMsg13 *>(msg);
    //casted_msg->setHopcount(casted_msg->getHopcount()+1);

    int n = gateSize("out");
    //selecting a random number between 0 to n-1. Not for each node the gate size might vary.
    int k = intuniform(0, n - 1);

    char printing_msg[50];
    sprintf(printing_msg,"forwarding on port k=%d at node=%d",k,getIndex());
    bubble(printing_msg);
    EV <<printing_msg;
    send(msg, "out", k);
}

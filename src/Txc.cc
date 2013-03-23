#include "Txc.h"

Define_Module(Txc);

Txc::Txc() {
    // TODO Auto-generated constructor stub

}

Txc::~Txc() {
    // TODO Auto-generated destructor stub
}

void Txc::initialize() {
    counter=par("limit");
    WATCH(counter);
    if (par("sendInitMessage").boolValue()==true) {

        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

void Txc::handleMessage(cMessage *msg) {
    counter--;
    if(counter==0)
    {
        EV << getName() << "counter reached zero, so deleting the message";
        delete msg;
    }
    else
    {
        EV << getName() << "counter value="<<counter;
    // just send back the message we received
    send(msg, "out");
    }
//    send(msg, "out");
}


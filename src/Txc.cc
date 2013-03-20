#include "Txc.h"

Define_Module(Txc);

Txc::Txc() {
    // TODO Auto-generated constructor stub

}

Txc::~Txc() {
    // TODO Auto-generated destructor stub
}

void Txc::initialize() {
    if (strcmp("Tic", getName()) == 0) {

        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

void Txc::handleMessage(cMessage *msg) {
    // just send back the message we received
    send(msg, "out");
}


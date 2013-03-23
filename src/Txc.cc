#include "Txc.h"

Define_Module(Txc);

Txc::Txc() {
    tictocmsg=NULL;
    event=NULL;
}

Txc::~Txc() {
}

void Txc::initialize() {
    //creating event object which will be used for timing
    event=new cMessage("event");

    counter=par("limit");
    WATCH(counter);
    if (par("sendInitMessage").boolValue()==true) {

        tictocmsg=new cMessage("tictocmsg");
        //scheduling tictoc message at 5.0 simulation time
        scheduleAt(5.0,tictocmsg);

    }
}

void Txc::handleMessage(cMessage *msg) {
/*
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
*/

    //if message is self message then the wait is over... send it
    if(msg==event)//you use this too  if(msg->isSelfMessage())
    {
        EV << "wait is over... send message";
        send(tictocmsg,"out");
        tictocmsg=NULL;
    }
    else
    {
        delay=par("delayTime");
       EV << "schedule message to wait. Delay="<<delay;
       tictocmsg=msg;
       scheduleAt(simTime()+delay,event);

    }
}


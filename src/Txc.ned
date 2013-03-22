package mytictoc;

simple Txc
{
    parameters:
        @display("i=block/telnet");
        bool sendInitMessage=default(false);
        int limit=default(2);
    gates:
        input in;
        output out;
}

network Tictoc
{
    submodules:
        Tic: Txc {
            parameters:
                @display("i=,cyan");
                sendInitMessage=true;
        }
        Toc: Txc {
            parameters:
                @display("i=,red");
                sendInitMessage=false;
        }
    connections:
        Tic.out --> {  delay = 100ms; } --> Toc.in;
        Toc.out --> {  delay = 200ms; } --> Tic.in;
}

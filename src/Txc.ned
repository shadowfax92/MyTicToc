package mytictoc;

simple Txc
{
    parameters:
        @display("i=block/telnet");
        bool sendInitMessage=default(false);
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
        }
        Toc: Txc {
            parameters:
                @display("i=,red");
        }
    connections:
        Tic.out --> {  delay = 100ms; } --> Toc.in;
        Toc.out --> {  delay = 200ms; } --> Tic.in;
}

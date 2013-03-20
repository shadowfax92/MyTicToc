package mytictoc;

simple Txc
{
    gates:
        input in;
        output out;
}

network Tictoc
{
    submodules:
        Tic: Txc;
        Toc: Txc;
    connections:
        Tic.out --> { delay = 100ms; } --> Toc.in;
        Toc.out --> { delay=100ms; } -->  Tic.in;
}

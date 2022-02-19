#include "lexer.h"
#include "inp.h"

int main(int argc, char *argv[]) {
    string fn = readFN(argc,argv); // read name of qube file containing the source code
    displayFile(fn); //performs lexical analysis of the source code
    return 0;
}
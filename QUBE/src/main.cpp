#include "lexer.h"
#include "inp.h"

int main(int argc, char *argv[]) {
    string fn = readFN(argc,argv);
    displayFile(fn);
    return 0;
}
#include "lexer.h"
#include "inp.h"
#include "parser.h"
int main(int argc, char *argv[]) {
    string fn = readFN(argc,argv);
    displayFile(fn);
    parser();
    return 0;
}
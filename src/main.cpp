#include "lexer.h"
#include "inp.h"
#include "parser.h"
int main(int argc, char *argv[]) {
    string fn = readFN(argc,argv);
    vector<string> tl = displayFile(fn);
    parser(tl);
    return 0;
}
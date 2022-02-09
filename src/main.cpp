#include "lexer.h"
#include "inp.h"

int main(int argc, char *argv[]) {
    string fn = readFN(argc,argv); // read name of qube source file
  
    displayFile(fn);
  
    return 0;
}
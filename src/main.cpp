#include "lexer.h"
#include "inp.h"

int main(int argc, char *argv[]) {
    string fn = readFN(argc,argv); // read name of qube file containing the source code
    int choice = 0;
    cout<<"Create new output file (yes: 1 or no: 0)?"<<endl;
    cin>>choice;
    displayFile(fn, choice); //performs lexical analysis of the source code
    return 0;
}
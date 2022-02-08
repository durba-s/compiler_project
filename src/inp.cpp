#include "utils.h"

string readFN(int argc, char *argv[]){
    if(argc==1){
            fprintf(stderr, "[error]File name not entered");
            exit(EXIT_FAILURE);
    }
    else if(argc>2){
            fprintf(stderr, "[error]Incorrect file name");
            exit(EXIT_FAILURE);
    }
    else{
        string fn = argv[1];
        regex filename("[_a-zA-Z0-9]+\\.q");
        if(regex_match(fn, filename)){
            cout << "filename = "<< fn << endl;
            return fn;
        }
        else{
            fprintf(stderr, "[error]Invalid qube file name");
            exit(EXIT_FAILURE);
        }
    }

}
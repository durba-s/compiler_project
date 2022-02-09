#include "constants.h"
#include "inp.h"

string readFN(int argc, char *argv[]){
    if(argc == 1){
            fprintf(stderr, "[error]File name not entered");
            exit(EXIT_FAILURE);
    }
    else if(argc>2){
            fprintf(stderr, "[error]Incorrect file name");
            exit(EXIT_FAILURE);
    }
    else{
        string fn = argv[1];
        if(regex_match(fn, FILENAME)){
            return fn;
        }
        else{
            fprintf(stderr, "[error]Invalid qube file name");
            exit(EXIT_FAILURE);
        }
    }

}
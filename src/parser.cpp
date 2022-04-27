#include "parser.h"
/*
handleShift()
handleReduce()
handleGoto()
readParseTable()
*/
void parser(){
    Json::Value root;
    Json::Reader reader;

    std::ifstream file("./FINALGrammar/gmrFINAL.json");
    file >> root;
    cout<<root["1"]["LHS"]<<endl;
}
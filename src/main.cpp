#include "lexer.h"
#include "inp.h"
#include "parser.h"
int main(int argc, char *argv[]) {
    string fn = readFN(argc,argv);
    vector<pair<string,string> >  tl = displayFile(fn);
    vector<string> rules = parser(tl,fn);
    /*Json::Value root;
    regex re("\"|\n|\\[|\\]");
    Json::FastWriter fastWriter;
    ifstream file("./FINALGrammar/gmrFINAL.json");
    ofstream out("in_rules.txt");
    file >> root;
    for(int i=rules.size()-1;i>=0;i--){
        out<<regex_replace(fastWriter.write(root[rules[i]]["LHS"]),re,"")<<" "<<regex_replace(fastWriter.write(root[rules[i]]["RHS"]),re,"")<<endl;
    }
    file.close();
    out.close();
    */

    return 0;
}



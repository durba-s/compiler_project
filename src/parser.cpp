#include "parser.h"
/*
handleShift()
handleReduce()
handleGoto()
readParseTable()
*/
vector< pair<string,string> > parseStack;
regex re("\"|\n");
Json::FastWriter fastWriter;
int inpIdx = 0;
void printStack(){
    for(int i = 0;i < parseStack.size();i++){
        if(i>0){
            cout<<parseStack[i].second<<" ";
            cout<<parseStack[i].first<<" ";
        }
        else{
            cout<<parseStack[i].first<<" ";
        }
    }
    cout<<endl;
}
void handleShift(string inp, string state){
    parseStack.push_back(make_pair(state,inp));
    inpIdx++;
}
void handleReduce(string rule){
    //cout<<"[REDUCE]"<<endl;
    Json::Value root;
    Json::Reader reader;
    ifstream file("./FINALGrammar/gmrFINAL.json");
    file >> root;
    Json::Value lhs = root[rule]["LHS"];
    int len = root[rule]["RHS"].size();
    file.close();
    for(int i = 0;i<len;i++){
        parseStack.pop_back();
    }
    string currState = parseStack[parseStack.size()-1].first;
    string nonTerminal = regex_replace(fastWriter.write(lhs),re,"");
    string nextState = handleGoto(nonTerminal,currState);
    //cout<<nextState<<endl;
    parseStack.push_back(make_pair(nextState,nonTerminal));
    //cout<<"[done]"<<endl;
    return;
}
string handleGoto(string nt,string state){
    Json::Value root;
    Json::Reader reader;
    ifstream file("./FINALGrammar/gotoTable.json");
    file >> root;
    Json::Value json = root[state][nt];
    string curr = fastWriter.write(json);
    file.close();
    return regex_replace(curr,re,"");
}
void parser(vector<string> tok_list){

    tok_list.push_back("$");
    parseStack.push_back(make_pair("0","")); //initialize stack
    //cout<<parseStack.top().first;
    int n = tok_list.size();

    ifstream pt("./FINALGrammar/lalrTable.json");
    Json::Value root;
    pt >> root;
    while(inpIdx < n){
        string input = tok_list[inpIdx];
        string state = parseStack[parseStack.size()-1].first;
        Json::Value act = root[state][input];
        if(act){
            printStack();
            string action = regex_replace(fastWriter.write(act),re,"");
            char type = action[0];
            if(type=='s'){
                string num = action.substr(1,action.size());
                handleShift(input,num);
            }
            else if(type=='r'){
                string num = action.substr(1,action.size());
                handleReduce(num);
            }
            else if(type=='a'){
                cout<<"parsing successfull..."<<endl;
                break;
            }
        }
        else{
            cout<<"parsing error...\nskipping current input symbol..."<<endl;
            break;
        }
    }
}


    /*std::ifstream file("./FINALGrammar/gmrFINAL.json");
    file >> root;
    Json::StreamWriterBuilder builder;
    regex re("\"");
    Json::Value json = root["45"]["RHS"][0];
    builder["indentation"] = ""; // If you want whitespace-less output
    const std::string output = Json::writeString(builder, json);
    cout<<regex_replace(output, re, "");*/

   /* Json::Value root;
    Json::Reader reader;
   std::ifstream file("./FINALGrammar/gotoTable.json");
    file >> root;
    string r="3";
    Json::Value json = root[r]["PROGRAM"];
    cout<<json;*/

/*
cout<<"parsing error...\nskipping current input symbol..."<<endl;
        inpIdx++;
        return;
*/
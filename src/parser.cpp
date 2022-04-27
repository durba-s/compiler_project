#include "parser.h"

class symbol{
    public:
    string symbolName;
    string val;
    string temp="";
    string code="";
    int type;
    symbol(string nm){
        symbolName = nm;
        type = 0; //for non-terminals
    }
    symbol(string nm,string v){
        symbolName = nm;
        val = v;
        type = 1; //for terminals
    }
    void printCode(){
        cout<<code<<endl;
    }
};

int tempIdx = 0;
int labelIdx = 0;

string getTemp(){
    string stri = to_string(tempIdx);
    tempIdx++;
    string tempVar = "t"+stri;
    return tempVar;
}

string getLabel(){
    string stri = to_string(labelIdx);
    labelIdx++;
    string tempVar = "l"+stri;
    return tempVar;
}

vector< pair<string,symbol> > parseStack;
regex re("\"|\n");
Json::FastWriter fastWriter;

int inpIdx = 0;
int err = 0;

void printStack(ofstream& er){
    er<<"------------------------------------------------------"<<endl;
    er<<"[STACK]: ";
    for(int i = 0;i < parseStack.size();i++){
        if(i>0){
            er<<parseStack[i].second.symbolName<<" ";
            er<<parseStack[i].first<<" ";
        }
        else{
            er<<parseStack[i].first<<" ";
        }
    }
    er<<endl;
}


void handleShift(pair<string,string> inp, string state){
    symbol newInp = symbol(inp.first,inp.second);
    parseStack.push_back(make_pair(state,newInp));
    inpIdx++;
}


void handleReduce(string rule,ofstream& ic){
    //cout<<"[REDUCE]"<<endl;
    Json::Value root;
    Json::Reader reader;
    ifstream file("./FINALGrammar/gmrFINAL.json");
    file >> root;
    Json::Value lhs = root[rule]["LHS"];
    int len = root[rule]["RHS"].size();
    file.close();


    string nonTerminal = regex_replace(fastWriter.write(lhs),re,"");
    symbol newInp = symbol(nonTerminal);

    //generating intermediate code
    int ruleNum =  stoi(rule);

    if(ruleNum==66||ruleNum==67||ruleNum>=72||ruleNum==61||ruleNum==62||ruleNum==63||ruleNum==56){
        newInp.temp = parseStack[parseStack.size()-1].second.val;
    }

    if(ruleNum==64||ruleNum==68||ruleNum==69||ruleNum==70||ruleNum==71||ruleNum==57){
        newInp.temp = parseStack[parseStack.size()-1].second.temp;
    }

    if(ruleNum==53){
        newInp.temp = getTemp();
        newInp.code = parseStack[parseStack.size()-4].second.code + parseStack[parseStack.size()-2].second.code;
        string op1 = parseStack[parseStack.size()-4].second.temp;
        string op2 = parseStack[parseStack.size()-2].second.temp;
        string op = parseStack[parseStack.size()-3].second.temp;
        if(relop.find(op) == relop.end()){
            string genCode = newInp.temp+" = "+op1+op+op2+"\n";
            newInp.code = newInp.code + genCode;
            //ic<<genCode<<endl;
        }
        else{
            string l1 = getLabel();
            string l2 = getLabel();
            string genCode = "if "+op1+op+op2+" goto "+l1+"\n"+newInp.temp+" = 0\ngoto "+l2+"\n"+l1+":\n"+newInp.temp+" = 1\n"+l2+":\n";
            //ic<<genCode<<endl;
            newInp.code = newInp.code + genCode;
        }
    }

    if(ruleNum==54){
        newInp.temp = getTemp();
        newInp.code = parseStack[parseStack.size()-1].second.code;
        string op1 = parseStack[parseStack.size()-1].second.temp;
        string op = parseStack[parseStack.size()-2].second.temp;
        newInp.code = newInp.code + newInp.temp+"="+op+op1+"\n";
        //ic<< newInp.temp+"="+op+op1<<endl;
    }

    if(ruleNum==9||ruleNum==10||ruleNum==16){
        newInp.code = parseStack[parseStack.size()-1].second.code;
    }

    if(ruleNum==18){
        newInp.code = parseStack[parseStack.size()-2].second.code;
        string genCode = parseStack[parseStack.size()-4].second.val + parseStack[parseStack.size()-3].second.val + parseStack[parseStack.size()-2].second.temp+"\n";
        newInp.code = newInp.code+genCode;
        //ic<<genCode<<endl;
    }

    if(ruleNum==20){
        newInp.code = parseStack[parseStack.size()-3].second.code;
        string genCode = parseStack[parseStack.size()-4].second.val + parseStack[parseStack.size()-3].second.temp + parseStack[parseStack.size()-2].second.temp+"\n";
        newInp.code = newInp.code+genCode;
        //ic<<genCode<<endl;
    }

    if(ruleNum==33){
        newInp.code = parseStack[parseStack.size()-2].second.code;
        ic<<newInp.code<<endl;
    }

    if(ruleNum==5||ruleNum==6){
        newInp.code = parseStack[parseStack.size()-1].second.code;
    }

    if(ruleNum==4){
        newInp.code = parseStack[parseStack.size()-2].second.code+parseStack[parseStack.size()-1].second.code;
    }

    if(ruleNum==7){
        newInp.code = parseStack[parseStack.size()-2].second.code;
    }

    if(ruleNum==22){
        newInp.code = parseStack[parseStack.size()-5].second.code;
        string op = parseStack[parseStack.size()-5].second.temp;
        string sel = parseStack[parseStack.size()-1].second.code;
        string si = parseStack[parseStack.size()-3].second.code;
        string l1=getLabel();
        string l2=getLabel();
        string genCode = "if "+op+"= 0"+" goto "+l1+"\n"+si+"goto "+l2+"\n"+l1+":\n"+sel+l2+":\n";
        newInp.code = newInp.code+genCode;

    }


    for(int i = 0;i<len;i++){
        parseStack.pop_back();
    }
    string currState = parseStack[parseStack.size()-1].first;
    string nextState = handleGoto(nonTerminal,currState);
    //cout<<nextState<<endl;
    parseStack.push_back(make_pair(nextState,newInp));
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


vector<string> parser(vector<pair<string,string> > tok_list,string _fname){

    vector<string> prodRules;

    regex r("\\.q");
    string out_file= regex_replace( _fname, r, "_out.txt"); //creating the output file.
    ofstream out(out_file);
    ofstream& er(out);

    string tac_file= regex_replace( _fname, r, "_tac.txt"); //creating the ic file.
    ofstream tac(tac_file);
    ofstream& icode(tac);

    tok_list.push_back(make_pair("$","$"));
    parseStack.push_back(make_pair("0",symbol(""))); //initialize stack
    //cout<<parseStack.top().first;
    int n = tok_list.size();

    ifstream pt("./FINALGrammar/lalrTable.json");
    Json::Value root;
    pt >> root;
    while(inpIdx < n && parseStack.size()>0){
        string input = tok_list[inpIdx].first;
        string state = parseStack[parseStack.size()-1].first;
        Json::Value act = root[state][input];
        printStack(er);
        out<<"[STATE]: "<<state<<endl;
        out<<"[INP_SYM]: "<<input<<endl;
        out<<"[INP]: "<<tok_list[inpIdx].second<<endl;
        if(act){
            string action = regex_replace(fastWriter.write(act),re,"");
            char type = action[0];
            out<<"[ACTION]: "<<action<<endl;
            if(type=='s'){
                string num = action.substr(1,action.size());
                handleShift(tok_list[inpIdx],num);
            }
            else if(type=='r'){
                string num = action.substr(1,action.size());
                handleReduce(num,icode);
                prodRules.push_back(num);
            }
            else if(type=='a'){
                if(err==0)
                    out<<"valid program..."<<endl;
                else
                    out<<"there is error in the program..."<<endl;
                break;
            }
        }
        else{
            //cout<<"parsing error...\nskipping current input symbol..."<<endl;
            //inpIdx++;
            //break;
            out<<"[ACTION]: null"<<endl;
            out<<"parsing error...\npopping stack symbol..."<<endl;
            parseStack.pop_back();
            err = 1;
            //break;
        }
    }
    out<<"parsing completed..."<<endl;
    out.close();
    return prodRules;
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
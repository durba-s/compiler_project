#include "parser.h"

/*
* A node of a parse tree/ an element of the parse stack
* ->consists of the symbol name and it's attributes
**/
class symbol{
    public:
    string symbolName; //category of the terminal/non terminal
    string val; //terminal attribute: (stores the actual lexeme)
    string temp="";  //non-terminal attribute: name of the variable in 3ac
    string code=""; //non-terminal attribute: 3ac of the node and it's subtrees in the parse tree
    symbol(string nm){ //initialize non-terminal
        symbolName = nm;
    }
    symbol(string nm,string v){
        symbolName = nm; //initialize terminal
        val = v;
    }
};

int tempIdx = 0; //index of current temporary variable name
int labelIdx = 0; //index of current label name

/*
*function to generate a new temporary variable name
**/
string getTemp(){
    string stri = to_string(tempIdx);
    tempIdx++;
    string tempVar = "t"+stri;
    return tempVar;
}

/*
*function to generate a new label
**/
string getLabel(){
    string stri = to_string(labelIdx);
    labelIdx++;
    string tempVar = "l"+stri;
    return tempVar;
}

/* Parse stack:
*-> Has elements and states
**/
vector< pair<string,symbol> > parseStack;

regex re("\"|\n"); //regex to remove ",",\n after reading from json file
Json::FastWriter fastWriter; //json writer to convert json::val to std::string


int inpIdx = 0; //current index in the token string

int err = 0; //0 if the code is correct, 1 if parsing error occurs

/*
*function to print the current parse stack contents
**/
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

/*
*Performs shift action
* ->Read a token, remove it from the token list and push to the parse stack
* ->Add the top state of the stack from the shift number
**/
void handleShift(pair<string,string> inp, string state){
    symbol newInp = symbol(inp.first,inp.second);
    parseStack.push_back(make_pair(state,newInp));
    inpIdx++;
}

/*
*Performs reduce action and generates 3ac by applying the corresponding SDD of the production rule used in the reduce action
* To perform reduce action:
* ->pop the top elements of the stack corresponding to the RHS of the production rule indicated by the reduce action number
* ->get the nextState using goto
* ->push the non-terminal in the LHS of the production rule used and the state obtained from goto table to the parse stack
**/
void handleReduce(string rule,ofstream& ic){
    //cout<<"[REDUCE]"<<endl;
    Json::Value root;
    Json::Reader reader;
    ifstream file("./FINALGrammar/gmrFINAL.json"); //json file containing the grammar rules
    file >> root;
    Json::Value lhs = root[rule]["LHS"];
    int len = root[rule]["RHS"].size();
    file.close();


    string nonTerminal = regex_replace(fastWriter.write(lhs),re,"");
    symbol newInp = symbol(nonTerminal);

    /*generating intermediate code*/

    int ruleNum =  stoi(rule);

    /*SDD*/
    if(ruleNum==66||ruleNum==67||ruleNum>=72||ruleNum==61||ruleNum==62||ruleNum==63||ruleNum==56){
        newInp.temp = parseStack[parseStack.size()-1].second.val;
    }
    /*SDD*/
    if(ruleNum==64||ruleNum==68||ruleNum==69||ruleNum==70||ruleNum==71||ruleNum==57){
        newInp.temp = parseStack[parseStack.size()-1].second.temp;
    }
    /*SDD*/
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
    /*SDD*/
    if(ruleNum==54){
        newInp.temp = getTemp();
        newInp.code = parseStack[parseStack.size()-1].second.code;
        string op1 = parseStack[parseStack.size()-1].second.temp;
        string op = parseStack[parseStack.size()-2].second.temp;
        newInp.code = newInp.code + newInp.temp+"="+op+op1+"\n";
        //ic<< newInp.temp+"="+op+op1<<endl;
    }
    /*SDD*/
    if(ruleNum==9||ruleNum==10||ruleNum==16){
        newInp.code = parseStack[parseStack.size()-1].second.code;
    }
    /*SDD*/
    if(ruleNum==18){
        newInp.code = parseStack[parseStack.size()-2].second.code;
        string genCode = parseStack[parseStack.size()-4].second.val + parseStack[parseStack.size()-3].second.val + parseStack[parseStack.size()-2].second.temp+"\n";
        newInp.code = newInp.code+genCode;
        //ic<<genCode<<endl;
    }
    /*SDD*/
    if(ruleNum==20){
        newInp.code = parseStack[parseStack.size()-3].second.code;
        string genCode = parseStack[parseStack.size()-4].second.val + parseStack[parseStack.size()-3].second.temp + parseStack[parseStack.size()-2].second.temp+"\n";
        newInp.code = newInp.code+genCode;
        //ic<<genCode<<endl;
    }
    /*SDD*/
    if(ruleNum==33){
        newInp.code = parseStack[parseStack.size()-2].second.code;
        ic<<newInp.code<<endl;
    }
    /*SDD*/
    if(ruleNum==5||ruleNum==6){
        newInp.code = parseStack[parseStack.size()-1].second.code;
    }
    /*SDD*/
    if(ruleNum==4){
        newInp.code = parseStack[parseStack.size()-2].second.code+parseStack[parseStack.size()-1].second.code;
    }
    /*SDD*/
    if(ruleNum==7){
        newInp.code = parseStack[parseStack.size()-2].second.code;
    }
    /*SDD*/
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


    /*performing reduce action*/

    for(int i = 0;i<len;i++){
        parseStack.pop_back();
    }
    string currState = parseStack[parseStack.size()-1].first;

    /*get state using goto*/
    string nextState = handleGoto(nonTerminal,currState);

    /*push the non-terminal to the left of the production rule used and the state obtained from goto table to the parse stack*/
    parseStack.push_back(make_pair(nextState,newInp));

    return;
}

/*
* Performs goto action
* ->Takes the non-terminal and current state as input parameters
* ->Returns the next state number using the goto table and input parameters
**/
string handleGoto(string nt,string state){
    Json::Value root;
    Json::Reader reader;
    ifstream file("./FINALGrammar/gotoTable.json"); //json file containing the goto table
    file >> root;
    Json::Value json = root[state][nt];
    string curr = fastWriter.write(json);
    file.close();
    return regex_replace(curr,re,"");
}

/*
* Performs the parsing
* ->initialize the parse stack and append $ to the end of the token list
* ->Read input tokens and add it to the parse stack or update the parse stack using production rules 
*       based on the entry in the lalr parse table corresponding to the current input symbol and 
*       state on top of the stack
*-> Once we arrive at the 'acc' entry of the lalr table, the input tok list is entirely scanned or the parse stack is empty; parsing is completed
*-> Error handling:
*->   option1:  Scan down the stack until a state S with a goto on a particular nonterminal A is found
*->   option2:  Discard zero or more input symbols until a symbol a is found that can legitimately follow A.
*returns the sequence in which the production rules are applied and the corresponding production rules 
**/
vector<string> parser(vector<pair<string,string> > tok_list,string _fname,int option){

    //to store the prod rules sequence
    vector<string> prodRules;

    //creating output files
    //output1: stack contents at each step
    //output2: Intermediate code in the form of three address code
    regex r("\\.q");
    string out_file= regex_replace( _fname, r, "_out.txt"); //to store stack contents
    ofstream out(out_file);
    ofstream& er(out);
    string tac_file= regex_replace( _fname, r, "_tac.txt"); //to store Intermediate code
    ofstream tac(tac_file);
    ofstream& icode(tac);

    //append $ to token list
    tok_list.push_back(make_pair("$","$"));
    //initialize the parse stack
    parseStack.push_back(make_pair("0",symbol("")));

    //size of the token list
    int n = tok_list.size();

    //read the lalr parse table
    ifstream pt("./FINALGrammar/lalrTable.json"); //json file containing the lalr table
    Json::Value root;
    pt >> root;

    //read the next token, and perform action corresponding to the lalr parse table (get the cell using curr input token and curr state)
    //till all the tokens are read or parse stack is empty
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
            //shift
            if(type=='s'){
                string num = action.substr(1,action.size());
                handleShift(tok_list[inpIdx],num);
            }
            //reduce
            else if(type=='r'){
                string num = action.substr(1,action.size());
                handleReduce(num,icode);
                prodRules.push_back(num);
            }
            //accepted
            else if(type=='a'){
                if(err==0)
                    out<<"valid program..."<<endl;
                else
                    out<<"there is error in the program..."<<endl;
                break;
            }
        }
        //error handling
        else{
            out<<"[ACTION]: null"<<endl;
            if(option==1){
                out<<"parsing error...\npopping stack symbol..."<<endl;
                parseStack.pop_back();
            }
            else{
                cout<<"parsing error...\nskipping current input symbol..."<<endl;
                inpIdx++;
            }
            err = 1;
        }
    }
    out<<"parsing completed..."<<endl;
    out.close();
    tac.close();
    return prodRules;
}
#include "utils.h"
#include "json/json-forwards.h"
#include "json/json.h"
#include <stack>
#include<vector>
#include<regex>
#include <string>
#include <set>
using namespace std;

//set of relational operators
const set<string> relop = {
        ">",
        ">=",
        "<",
        "<=",
        "==",
        "!=",
        "&&",
        "||"
};

/*
*function to generate a new temporary variable name
**/
string getTemp();

/*
*function to generate a new label
**/
string getLabel();

/*
*function to print the current parse stack contents
**/
void printStack(ofstream& er);

/*
*Function to perform shift action
**/
void handleShift(string inp, int state);

/*
*Function to perform reduce action
**/
void handleReduce(string rule,ofstream& ic);

/*
*Function to perform goto
**/
string handleGoto(string nt,string state);

/*
*Parser function
*->Reads the input token and parse table and performs the necessary actions(shift/reduce/goto)
**/
vector<string> parser(vector<pair<string,string> > tok_list,string _fname,int option);
#include "utils.h"
#include "json/json-forwards.h"
#include "json/json.h"
#include <stack>
#include<vector>
#include<regex>
#include <string>
#include <set>
using namespace std;
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

string getTemp();
string getLabel();
void printStack(ofstream& er);
void handleShift(string inp, int state);
void handleReduce(string rule,ofstream& ic);
string handleGoto(string nt,string state);
vector<string> parser(vector<pair<string,string> > tok_list,string _fname);
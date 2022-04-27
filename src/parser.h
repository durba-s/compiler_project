#include "utils.h"
#include "json/json-forwards.h"
#include "json/json.h"
#include <stack>
#include<vector>
#include<regex>
using namespace std;
typedef struct{
    string op1;
    string op2;
    string op;
    string res;
} quadruple;
void printStack(ofstream& er);
void handleShift(string inp, int state);
void handleReduce(string rule);
string handleGoto(string nt,string state);
vector<string> parser(vector<pair<string,string> > tok_list,string _fname);
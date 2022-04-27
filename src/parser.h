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
void handleShift(string inp, int state);
void handleReduce(string rule);
string handleGoto(string nt,string state);
void parser(vector<string> tok_list);
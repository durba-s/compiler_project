#include <iostream>
#include <set>
#include <string>
#include <regex>
using namespace std;

string getNextToken();

void getChar();
void addChar();

bool isBlank(string s);
bool isDelimiter(string s);
bool isKeyword();
bool isIdentifier();
string isLiteral();

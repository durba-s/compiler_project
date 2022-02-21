#include <fstream>
#include <iostream>
using namespace std;
using std::ifstream;

int openSourceFile(string _fname);
int closeSourceFile();

int getLineNo();

bool isEOF();
string getNextLexeme(ofstream& err);
void handleError(string message, ofstream& err);

bool isKeyword(string s);
bool isIdentifier(string s);
bool isOperator(string s);
bool isSpecialSymbol(string s);
string isLiteral(string s);

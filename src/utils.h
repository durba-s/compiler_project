#include <fstream>

using namespace std;
using std::ifstream;

int openSourceFile(string _fname);
int closeSourceFile();

int getLineNo();

bool isEOF();
string getNextLexeme();

bool isKeyword(string s);
bool isIdentifier(string s);
bool isOperator(string s);
bool isSpecialSymbol(string s);
string isLiteral(string s);

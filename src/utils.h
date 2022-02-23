#include <fstream>
#include <iostream>
using namespace std;
using std::ifstream;

/**
 * Opens _fname and initialized the input stream with it.
 * */
int openSourceFile(string _fname);

/**
 *  Closes the opened file.
 * */
int closeSourceFile();

/**
 * Returns the current line number in the input file.
 * */
int getLineNo();

/**
 * Returns true if the input stream has reached EOF else returns false.
 * */
bool isEOF();

/**
 * Returns the next lexeme if available else returns an empty string.
 * */
string getNextLexeme(ofstream& err);

/**
 * Prints the error message in the err stream and exits the program.
 * */
void handleError(string message, ofstream& err);

bool isKeyword(string s);
bool isIdentifier(string s);
bool isOperator(string s);
bool isSpecialSymbol(string s);
string isLiteral(string s);

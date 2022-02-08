#include "utils.h"

char curr , next;
string lexeme;

regex INT("[+-]?[0-9]+");
regex FLOAT("[+-]?[0-9]*\\.?[0-9]+");
regex CHAR("'.'");
regex BOOL("true|false");
regex STRING("\"(\\\\.|[^\"\\\\])*\"");
regex IDENTIFIER("[_a-zA-Z][_a-zA-Z0-9]{0,30}");


string getNextToken(){
    return lexeme;
}

char getChar(){

}

void addChar(){

}

bool isDelimiter(){

}

bool isKeyword(){

}


bool isIdentifier(){
    if(regex_match(lexeme , IDENTIFIER))
        return true;
    else
        return false;
}

string isLiteral(){
    if(regex_match(lexeme , INT))
        return "INTEGER_LITERAL";
    if(regex_match(lexeme , FLOAT))
        return "FLOAT_LITERAL";
    if(regex_match(lexeme , CHAR))
        return "CHARACTER_LITERAL";
    if(regex_match(lexeme , BOOL))
        return "BOOLEAN_LITERAL";
    if(regex_match(lexeme , STRING))
        return "STRING_LITERAL";
    return "ERROR";
}
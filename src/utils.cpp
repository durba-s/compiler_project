#include "utils.h"

char curr , next;
std::string lexeme;

std::regex INT("[+-]?[0-9]+");
std::regex FLOAT("[+-]?[0-9]*\\.?[0-9]+");
std::regex CHAR("'.'");
std::regex BOOL("true|false");
std::regex STRING("\"(\\\\.|[^\"\\\\])*\"");

std::string getNextToken(){
    return lexeme;
}

char getChar(){

}
void addChar(){

}


bool isKeyword(){

}
bool isIdentifier(){

}
bool isDelimiter(){

}
std::string isLiteral(){
    if(std::regex_match(lexeme , INT))
        return "INTEGER_LITERAL";
    if(std::regex_match(lexeme , FLOAT))
        return "FLOAT_LITERAL";
    if(std::regex_match(lexeme , CHAR))
        return "CHARACTER_LITERAL";
    if(std::regex_match(lexeme , BOOL))
        return "BOOLEAN_LITERAL";
    if(std::regex_match(lexeme , STRING))
        return "STRING_LITERAL";
    return "ERROR";
}
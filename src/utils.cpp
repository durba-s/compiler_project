#include "utils.h"
char curr , next;
string lexeme;

regex INT("[+-]?[0-9]+");
regex FLOAT("[+-]?[0-9]*\\.?[0-9]+");
regex CHAR("'.'");
regex BOOL("true|false");
regex STRING("\"(\\\\.|[^\"\\\\])*\"");
regex IDENTIFIER("[_a-zA-Z][_a-zA-Z0-9]{0,30}");
regex BLANK("[\\s\t]+");

const set<string> keys = {
        "if",
        "elif",
        "for",
        "in",
        "while",
        "do",
        "return",
        "break",
        "continue",
        "select",
        "case",
        "default",
        "def",
        "global",
        "static",
        "const",
        "int",
        "float",
        "char",
        "bool",
        "string",
        "true",
        "false",
        "void"
    };
const set<string> delims = {"{","}",
            ";",
            ",",
            "[",
            "]",
            "(",
            ")",
            ":",
            "?",
            "-",
            "*",
            "/",
            "%",
            ">",
            ">=",
            "<",
            "<=",
            "!=",
            "&&",
            "||",
            "!",
            "&",
            "|",
            "<<",
            ">>",
            "^",
            "--",
            "~",
            "=",
            "+=",
            "-=",
            "=>"
        };

string getNextToken(){
    return lexeme;
}

void getChar(){

}

void addChar(){

}

bool isBlank(string s){
    if(regex_match(s , BLANK))
        return true;
    else
        return false;
}

bool isDelimiter(string s){
    if(delims.find(s)!=delims.end())
        return true;
    else
        return false;
}

bool isKeyword(){
    if(keys.find(lexeme)!=keys.end())
        return true;
    else
        return false;

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
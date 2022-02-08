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
    map<string, string> delims;
    delims["{"]= "{";
    delims[";"]=";";
    delims["}"]="}";
    delims[","]=",";
    delims["["]="[";
    delims["]"]="]";
    delims["("]="(";
    delims[")"]=")";
    delims[":"]=":";
    delims["?"]="?";
    delims["-"]="-";
    delims["*"]="*";
    delims["/"]="/";
    delims["%"]="%";
    delims[">"]=">";
    delims[">="]= ">=";
    delims["<"]="<";
    delims["<="]= "<=";
    delims["!="]= "!=";
    delims["&&"]= "&&";
    delims["||"]= "||";
    delims["!"]="!";
    delims["&"]="&";
    delims["|"]="|";
    delims["<<"]= "<<";
    delims[">>"]= ">>";
    delims["^"]="^";
    delims["--"]= "--";
    delims["~"]="~";
    delims["="]="=";
    delims["+="]= "+=";
    delims["-="]= "-=";
    delims["=>"]= "=>";
    if(delims.find(s)!=delims.end())
        return true;
    else
        return false;
}

bool isKeyword(){
    map<string, string> keywd;
    keywd["if"] = "if";
    keywd["elif"] = "elif";
    keywd["else"] = "else";
    keywd["for"] = "for";
    keywd["in"] = "in";
    keywd["while"] = "while";
    keywd["do"] = "do";
    keywd["return"] = "return";
    keywd["break"] = "break";
    keywd["continue"] = "continue";
    keywd["select"] = "select";
    keywd["case"] = "case";
    keywd["default"] = "default";
    keywd["def"] = "def";
    keywd["global"] = "global";
    keywd["static"] = "static";
    keywd["const"] = "const";
    keywd["int"] = "int";
    keywd["float"] = "float";
    keywd["char"] = "char";
    keywd["bool"] = "bool";
    keywd["string"] = "string";
    keywd["true"] = "true";
    if(keywd.find(lexeme)!=keywd.end())
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
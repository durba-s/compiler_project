#include <iostream>
#include <map>
#include <regex>
using namespace std;

bool isKeyword(string s){
    map<string, string> keys = {
        {"if", "if"},
        {"elif", "elif"},
        {"else", "else"},
        {"for", "for"},
        {"in", "in"},
        {"while", "while"},
        {"do", "do"},
        {"return", "return"},
        {"break", "break"},
        {"continue", "continue"},
        {"select", "select"},
        {"case", "case"},
        {"default", "default"},
        {"def", "def"},
        {"global", "global"},
        {"static", "static"},
        {"const", "const"},
        {"int", "int"},
        {"float", "float"},
        {"char", "char"},
        {"bool", "bool"},
        {"string", "string"},
        {"true", "true"},
        {"true", "true"}
    };
    if(keys.find(s)!=keys.end())
        return true;
    else
        return false;
}

bool isDelim(string s){
    string blank = "[\\s\t]+";
    if(regex_match(s, regex(blank)))
        return true;
    else{
        map<string, string> delims = {
            {"{", "{"},
            {"}", "}"},
            {";", ";"},
            {",", ","},
            {"[", "["},
            {"]", "]"},
            {"(", "("},
            {")", ")"},
            {":", ":"},
            {"?", "?"},
            {"-", "-"},
            {"*", "*"},
            {"/", "/"},
            {"%", "%"},
            {">", ">"},
            {">=", ">="},
            {"<", "<"},
            {"<=", "<="},
            {"!=", "!="},
            {"&&", "&&"},
            {"||", "||"},
            {"!", "!"},
            {"&", "&"},
            {"|", "|"},
            {"<<", "<<"},
            {">>", ">>"},
            {"^", "^"},
            {"--", "--"},
            {"~", "~"},
            {"=", "="},
            {"+=", "+="},
            {"-=", "-="},
            {"=>", "=>"}
        };
        if(delims.find(s)!=delims.end())
            return true;
        else
            return false;
    }
}
int main(int argc, char** argv){
    string s;
    getline(cin, s);
    cout<<"*"<<s<<"*"<<"\n";
    cout << isDelim(s);
    return 0;
}
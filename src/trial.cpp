#include <iostream>
#include <set>
#include <regex>
using namespace std;
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
const set<string> delims = {
            "{",
            "}",
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

bool isKeyword(string s){
    
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
        
        if(delims.find(s)!=delims.end())
            return true;
        else
            return false;
    }
}
int main(int argc, char** argv){
    string s;
    getline(cin, s);
    //cout<<"*"<<s<<"*"<<"\n";
    cout << isDelim(s);
    return 0;
}
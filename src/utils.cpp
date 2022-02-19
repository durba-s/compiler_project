#include "utils.h"
#include "constants.h"

char curr , next;
string lexeme = "", delim = "";
int lc = 1;
ifstream inp;

void getChar(){
    if(!isEOF())
        inp >> noskipws >> curr;
}
int addChar(){
    lexeme.push_back(curr);
    return 1;
}

bool isDelimiter(string s){
    return isOperator(s) || isSpecialSymbol(s);
}

int openSourceFile(string _fname){
    inp.open(_fname);
    if(!inp){
        fprintf(stderr , "[error]File could not be opened");
        return 0;
    }
    inp >> noskipws >> curr;
    return 1;
}
int closeSourceFile(){
    inp.close();
    return 1;
}

int getLineNo(){
    return lc;
}

bool isEOF(){
    return inp.eof();
}

void handleDelimiter(){
    if(delim == "\n"){
        // NEW LINE
        lc++;
        delim = "";
    }
    else if(delim == " "){
        // WHITESPACES
        while(!isEOF() && curr == ' '){
            getChar();
        }
        delim = "";
    }
    else if(delim == "\""){
        // STRING LITERAL
        while(!isEOF() && curr != '"'){
            delim.push_back(curr);
            getChar();
        }
        delim.push_back(curr);
        getChar();
    }
    else if(delim == "#"){
        // COMMENT
        if(curr=='/'){
            while(!isEOF()){
                getChar();
            cj: if(curr=='/'){
                    getChar();
                    if(curr=='#')   break;
                    else if(curr=='/') goto cj;
                }
            }
            delim = "";
        }else{
            while(!isEOF() && curr != '\n')
            getChar();
            delim = "";
        }
    }else{
        // OPERATOR
        delim.push_back(curr);
        if(isDelimiter(delim))
            getChar();
        else
            delim.pop_back();
    }
}

string getNextLexeme(){

    if(delim != ""){
        string temp = delim;
        delim = "";
        return temp;
    }

    lexeme = "";
    delim = "";

    while(!isEOF()){
        if(isDelimiter(string(1,curr))){
            delim =  string(1 , curr);
            getChar();
            handleDelimiter();
            break;
        }
        addChar();
        getChar();
    }
    if(lexeme != "")
        return lexeme;
    if(delim != ""){
        string temp = delim;
        delim = "";
        return temp;
    }
    return "";
}


bool isKeyword(string s){
    return keys.find(s) != keys.end();
}
bool isIdentifier(string s){
    return regex_match(s , IDENTIFIER);
}
bool isOperator(string s){
    return operators.find(s) != operators.end();
}
bool isSpecialSymbol(string s){
    return special_symbols.find(s) != special_symbols.end();
}
string isLiteral(string s){
    if(regex_match(s , INT))
        return "INT_LIT";
    if(regex_match(s , FLOAT))
        return "FLOAT_LIT";
    if(regex_match(s , CHAR))
        return "CHAR_LIT";
    if(regex_match(s , BOOL))
        return "BOOL_LIT";
    if(regex_match(s , STRING))
        return "STR_LIT";
    return "ERROR";
}
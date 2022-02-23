#include "utils.h"
#include "constants.h"

char curr , next;
string lexeme = "", delim = "";
int lc = 1;
ifstream inp;

/**
 * Stores the next character in curr if available.
 * */
void getChar(){
    if(!isEOF())
        inp >> noskipws >> curr;
}

/**
 * Adds the current character to the current lexeme.
 * */
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

void handleError(string message , ofstream& err){
    err << "[error]" << message << "\t[LINE NO: " << getLineNo() << "]";
    exit(0);
}

/**
 * Takes proper actions depending upon the type of delimeter stored in delim.
 * */
void handleDelimiter(ofstream& err){
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
    else if(delim == "'"){
        // CHARACTER LITERAL
        if(curr == '\''){
            // ERROR
            handleError("empty char literal not allowed" , err);
        }
        else{
            delim.push_back(curr);
            getChar();
            if(curr != '\''){
                // ERROR
                handleError("missing terminating ' character" , err);
            }
            else{
                delim.push_back(curr);
            }
        }
        getChar();
    }
    else if(delim == "\""){
        // STRING LITERAL
        if(isEOF()){
            // ERROR
            handleError("missing terminating \" character" , err);
        }
        while(!isEOF() && curr != '"'){
            delim.push_back(curr);
            getChar();
        }
        if(curr != '"'){
            // ERROR
            handleError("missing terminating \" character" , err);
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

string getNextLexeme(ofstream& err){

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
            handleDelimiter(err);
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
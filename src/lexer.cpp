#include "lexer.h"

void displayFile(string _fname){

    if(!openSourceFile(_fname))
        exit(EXIT_FAILURE);
    
    while(!isEOF()){
        string lexeme = getNextLexeme();
        if(lexeme != ""){
            if(isKeyword(lexeme)){
                cout << "[KEYWORD]\t\t";
            }
            else if(isIdentifier(lexeme)){
                cout << "[IDENTIFIER]\t\t";
            }
            else if(isOperator(lexeme)){
                cout << "[OPERATOR]\t\t";
            }
            else if(isSpecialSymbol(lexeme)){
                cout << "[SPECIAL SYMBOL]\t";
            }
            else{
                string type = isLiteral(lexeme);
                if(type == "ERROR"){
                    cout << "[UNIDENTIFIED TOKEN]\t";
                }
                else{
                    cout << "[" << type << "]\t";
                }
            }
            cout << "[LINE NO: " << getLineNo() << "]\t\t" << lexeme << endl;
        }
    }

    closeSourceFile();
}
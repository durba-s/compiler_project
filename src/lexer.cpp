#include "lexer.h"
vector<string> tok_list;
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
vector<string> displayFile(string _fname){
    
    // A std::map which stores token-IDs.
    map<string, pair<string,int> > st = {
    {"+"       ,{"OP_AR_add    ",1} },
    {"-"       ,{"OP_AR_sub    ",2} },
    {"*"       ,{"OP_AR_mul    ",3} },
    {"/"       ,{"OP_AR_div    ",4} },
    {"%"       ,{"OP_AR_mod    ",5} },
    {">"       ,{"OP_REL_gt    ",6} },
    {">="     ,{"OP_REL_ge    ",7} },
    {"<"       ,{"OP_REL_lt    ",8} },
    {"<="      ,{"OP_REL_le    ",9} },
    {"=="      ,{"OP_REL_eq    ",10} },
    {"!="      ,{"OP_REL_neq   ",11} },
    {"&&"      ,{"OP_LOG_and   ",12} },
    {"||"      ,{"OP_LOG_or    ",13} },
    {"!"      ,{"OP_LOG_not   ",14} },
    {"&"      ,{"OP_BIT_and   ",15} },
    {"|"      ,{"OP_BIT_or    ",16} },
    {"<<"     ,{"OP_BIT_ls    ",17} },
    {">>"      ,{"OP_BIT_rs    ",18} },
    {"^"       ,{"OP_BIT_xor   ",19} },
    {"+="      ,{"OP_ASSGN1    ",20} },
    {"-="      ,{"OP_ASSGN2    ",21} },
    {"*="     ,{"OP_ASSGN3    ",22} },
    {"/="      ,{"OP_ASSGN4    ",23} },
    {"%="      ,{"OP_ASSGN5    ",24} },
    {"&="      ,{"OP_ASSGN6    ",25} },
    {"|="      ,{"OP_ASSGN7    ",26} },
    {"^="      ,{"OP_ASSGN8    ",27} },
    {"++"      ,{"OP_INCR      ",28} },
    {"--"      ,{"OP_DECR      ",29} },
    {"~"       ,{"OP_BIT4      ",30} },
    {"{"       ,{"SYM_P1       ",31} },
    {"}"       ,{"SYM_P2       ",32} },
    {";"       ,{"SYM_SEMICOLON",33} },
    {"="       ,{"OP_ASSGN     ",34} },
    {","       ,{"OP_COMMA     ",35} },
    {"["       ,{"SYM_SB1      ",36} },
    {"]"       ,{"SYM_SB2      ",37} },
    {"("       ,{"SYM_B1       ",38} },
    {")"       ,{"SYM_B2       ",39} },
    {":"       ,{"OP_TERN1     ",40} },
    {"=>"      ,{"OP_FUNC      ",41} },
    {"?"       ,{"OP_TERN2     ",42} },
    {"if"      ,{"KEYWD_IF     ",43} },
    {"elif"    ,{"KEYWD_ELIF   ",44} },
    {"else"    ,{"KEYWD_ELSE   ",45} },
    {"for"     ,{"KEYWD_FOR    ",46} },
    {"in"      ,{"KEYWD_IN     ",47} },
    {"while"   ,{"KEYWD_WHILE  ",48} },
    {"do"      ,{"KEYWD_DO     ",49} },
    {"return"  ,{"KEYWD_RETURN ",50} },
    {"break"   ,{"KEYWD_BREAK  ",61} },
    {"continue",{"KEYWD_CONTINUE",62} },
    {"select"  ,{"KEYWD_SELECT ",63} },
    {"case"    ,{"KEYWD_CASE   ",64} },
    {"default" ,{"KEYWD_DEFAULT",65} },
    {"def"    ,{"KEYWD_DEF    ",66} },
    {"global"  ,{"KEYWD_GLOBAL ",67} },
    {"static"  ,{"KEYWD_STATIC ",68} },
    {"const"   ,{"KEYWD_CONST  ",69} },
    {"int"     ,{"KEYWD_INT    ",70} },
    {"float"   ,{"KEYWD_FLOAT  ",81} },
    {"char"    ,{"KEYWD_CHAR   ",82} },
    {"bool"    ,{"KEYWD_BOOL   ",83} },
    {"void"    ,{"KEYWD_VOID   ",84} },
    {"string"  ,{"KEYWD_STRING ",85} },
    {"true"    ,{"KEYWD_TRUE   ",86} },
    {"false"   ,{"KEYWD_FALSE  ",87} }
     };
    map<string,int> st1= {
        {"INT_LIT",88},
        {"FLOAT_LIT",89},
        {"CHAR_LIT",90},
        {"STR_LIT",91},
        {"BOOL_LIT",92},
        {"IDENTIFIER",93}
    };


    regex r("\\.q");
    string out_file= regex_replace( _fname, r, "_lex_out.txt"); //creating the output file.
    ofstream lex_out(out_file);
    ofstream& err(lex_out);

    ofstream tok_out("toks.txt");

    if(!openSourceFile(_fname))
        exit(EXIT_FAILURE); // throw error if file can't be opened
    lex_out <<"Category\t\tToken ID\t  Line No\t\t\tLexeme\n";
    lex_out <<"--------------------------------------------------------------------\n";
    while(!isEOF()){
        string lexeme = getNextLexeme(err); // get the next lexeme.
        if(lexeme != ""){ 
            bool ok=true;

            // check if the obtained lexeme is a KEYWORD, IDENTIFIER, OPERATOR, SPECIAL SYMBOL or a LITERAL.

            if(isKeyword(lexeme)){
                map<string, pair<string,int> >::iterator tok=st.find(lexeme);
                lex_out << tok->second.first<<"\t\t"<<tok->second.second<<"\t\t";
                tok_out <<tok->second.first<<endl;
                tok_list.push_back(removeSpaces(tok->second.first));
            }
            else if(isIdentifier(lexeme)){
                map<string, int >::iterator tok=st1.find("IDENTIFIER");
                lex_out <<"IDENTIFIER\t\t\t"<<tok->second<<"\t\t";
                tok_out <<"IDENTIFIER"<<endl;
                tok_list.push_back("IDENTIFIER");
            }
            else if(isOperator(lexeme)){
                map<string, pair<string,int> >::iterator tok=st.find(lexeme);
                if(tok!=st.end()){
                    lex_out << tok->second.first<<"\t\t" <<tok->second.second<<"\t\t";
                    tok_out <<tok->second.first<<endl;
                    tok_list.push_back(removeSpaces(tok->second.first));
                }
                else{
                    ok=false;
                }
            }
            else if(isSpecialSymbol(lexeme)){
                map<string, pair<string,int> >::iterator tok=st.find(lexeme);
                if(tok!=st.end()){
                    lex_out << tok->second.first<<"\t\t"<<tok->second.second<<"\t\t";
                    tok_out <<tok->second.first<<endl;
                    tok_list.push_back(removeSpaces(tok->second.first));
                }
                else{
                    ok=false;
                }
            }
            else{
                string type = isLiteral(lexeme);
                if(type == "ERROR"){
                    // unable to specify the type of lexeme.
                    handleError("unidentified token: [" + lexeme + "]" , err);
                    ok=false;
                }
                else{
                    map<string, int >::iterator tok=st1.find(type);
                    lex_out << "[" << type << "]\t\t\t"<<tok->second<<"\t\t";
                    tok_out <<type<<endl;
                    tok_list.push_back(removeSpaces(type));
                }
            }
            if(ok)
                lex_out << "LINE NO: " << getLineNo() << "\t\t" << lexeme << endl;
        }
    }
      lex_out.close();
      tok_out.close();


    closeSourceFile();
    return tok_list;
}
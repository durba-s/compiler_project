#include<iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream out("grammar.json");
    ifstream in("tok.txt");
    out<<"{\n";
    for(int i=0;i<112;i++){
        string s1,s2;
        getline(in, s1);
        getline(in, s2);
        out<<"\""<<i+1<<"\": "<<"{"<<"\n\t \"LHS\": "<<"\""<<s1<<"\""<<",\n\t \"RHS\": "<<"\""<<s2<<"\""<<"\n},\n";
    }
    out<<"}";

}

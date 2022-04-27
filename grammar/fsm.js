// fsm-config: {"font" : "Arial"}
// fsm-config: {"nodeShape" : "diamond"}
// fsm-config: {"initialShape" : "component", "finalShape" : "tab"}


//identifier, literals-4, symbols, operators, keywords,start, unk

/*Alpha={a,b,..,z,A,B,..Z}
Digit={0,1,2,...,9}
Symbols={=,{,},[,],.....}
Operators={<,>,!=,==,.....}
Keywords={}
String Literal
Int Literal
Char Literal
FLoat literal
*/

var mainFsm = {
    name:'MainFsm',
    initial: "Start",
    final: ['Identifier','Int_Literal'],
    events: [
        {name:'\'',from:'Start',to: 'isChar'},
        {name:'any alphabet',from:'isChar',to: 'char'},
        {name:'\'',from:'char',to: 'Char_Literal'},
        {name:'keyword',from:'Start',to: 'keyword'},
        {name:'[_a-zA-Z]',from:'Start',to: 'Identifier'},
        {name:'[_a-zA-Z0-9]',from:'Identifier',to: 'Identifier'},
        {name:'[0-9]',from:'Start',to: 'Int_Literal'},
        {name:'[0-9]',from:'Int_Literal',to: 'Int_Literal'},
        {name:'\\"',from:'Start',to: 'isString'},
        {name:'any alphabet',from:'isString',to: 'isString'},
        {name:'\\"',from:'isString',to: 'String_Literal'},
        {name:'[0-9]',from:'Start',to: 'isFloat'},
        {name:'[0-9]',from:'isFloat',to: 'isFloat'},
        {name:'.',from:'isFloat',to: 'dot'},
        {name:'.',from:'Start',to: 'dot'},
        {name:'[0-9]',from:'dot',to: 'Float_Literal'},
        {name:'[0-9]',from:'Float_Literal',to: 'Float_Literal'},
        {name:'symbol',from:'Start',to: 'Symbol'},
        {name:'operator',from:'Start',to: 'Operator'},
    ],
    states:[
        {name:'Start', shape:'circle'},
        {name:'char', shape:'circle'},
        {name:'isString', shape:'circle'},
        {name:'isChar', shape:'circle'},
        {name:'Int_Literal', shape:'doublecircle'},
        {name:'Char_Literal', shape:'doublecircle'},
        {name:'String_Literal', shape:'doublecircle'},
        {name:'Identifier', shape:'doublecircle'},
        {name:'isFloat', shape:'circle'},
        {name:'dot', shape:'circle'},
        {name:'Operator', shape:'doublecircle'},
        {name:'Symbol', shape:'doublecircle'},
        {name:'Float_Literal', shape:'doublecircle'},
        {name:'keyword', shape:'doublecircle'},
    ]
}
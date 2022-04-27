# Compiler Project

### Compilation:
```sh
make clean && make
./qube filename.q
#the output of lexical analysis will be stored in filename_lex_out.txt
```
### Lexer Output:
###### Program:
```sh
# sample program
def main() => int{
    print("Hello\n");
    #/this is
    commented/#
    int b=3;
    int a = b>5?1:3;
    if(a>=b){
        int p=a+b;
    }
}
```
###### Output:
| Category		| Token ID	|   Line No		| 	Lexeme|
|----------|:-------------:|------:|------:|
|KEYWD_DEF    		|66		|[LINE NO: 2]		|def
|IDENTIFIER			|93		|[LINE NO: 2]		|main
|SYM_B1       		|38		|[LINE NO: 2]		|(
|SYM_B2       		|39		|[LINE NO: 2]		|)
|OP_FUNC      		|41		|[LINE NO: 2]		|=>
|KEYWD_INT    		|70		|[LINE NO: 2]		|int
|SYM_P1       		|31		|[LINE NO: 2]		|{
|IDENTIFIER			|93		|[LINE NO: 3]		|print
|SYM_B1       		|38		|[LINE NO: 3]		|(
|[STR_LIT]			|91		|[LINE NO: 3]		|"Hello\n"
|SYM_B2       		|39		|[LINE NO: 3]		|)
|SYM_SEMICOLON		|33		|[LINE NO: 3]		|;
|KEYWD_INT    		|70		|[LINE NO: 5]		|int
|IDENTIFIER			|93		|[LINE NO: 5]		|b
|OP_ASSGN     		|34		|[LINE NO: 5]		|=
|[INT_LIT]			|88		|[LINE NO: 5]		|3
|SYM_SEMICOLON		|33		|[LINE NO: 5]		|;
|KEYWD_INT    		|70		|[LINE NO: 6]		|int
|IDENTIFIER			|93		|[LINE NO: 6]		|a
|OP_ASSGN     		|34		|[LINE NO: 6]		|=
|IDENTIFIER			|93		|[LINE NO: 6]		|b
|OP_REL_gt    		|6		|[LINE NO: 6]		|>
|[INT_LIT]			|88		|[LINE NO: 6]		|5
|OP_TERN2     		|42		|[LINE NO: 6]		|?
|[INT_LIT]			|88		|[LINE NO: 6]		|1
|OP_TERN1     		|40		|[LINE NO: 6]		|:
|[INT_LIT]			|88		|[LINE NO: 6]		|3
|SYM_SEMICOLON		|33		|[LINE NO: 6]		|;
|KEYWD_IF     		|43		|[LINE NO: 7]		|if
|SYM_B1       		|38		|[LINE NO: 7]		|(
|IDENTIFIER			|93		|[LINE NO: 7]		|a
|OP_REL_ge    		|7		|[LINE NO: 7]		|>=
|IDENTIFIER			|93		|[LINE NO: 7]		|b
|SYM_B2       		|39		|[LINE NO: 7]		|)
|SYM_P1       		|31		|[LINE NO: 7]		|{
|KEYWD_INT    		|70		|[LINE NO: 8]		|int
|IDENTIFIER			|93		|[LINE NO: 8]		|p
|OP_ASSGN     		|34		|[LINE NO: 8]		|=
|IDENTIFIER			|93		|[LINE NO: 8]		|a
|OP_AR_add    		|1		|[LINE NO: 8]		|+
|IDENTIFIER			|93		|[LINE NO: 8]		|b
|SYM_SEMICOLON		|33		|[LINE NO: 8]		|;
|SYM_P2       		|32		|[LINE NO: 9]		|}
|SYM_P2       		|32		|[LINE NO: 10]		|}

# Project Team

- [Ankita Behera](https://github.com/rxndom266/)
- [Durba Satpathi](https://github.com/durba-s)
- [Prakhar Agarwal](https://github.com/PrAkHaR-BitsPilani)

```cpp
/**
 * Ankita Behera 2019A7PS0075H
 * Durba Satpathi 2019A7PS0972H
 * Prakhar Agarwal 2019A7PS0174H
 **/
```

# Compiler Project

### Compilation:
```sh
make clean && make
./qube filename.q
#the output of lexical analysis will be stored in filename_lex_out.txt
#the output of syntax analysis will be stored in filename_out.txt (stores parse stack contents)
#the intermediate code (3ac) will be stored in filename_tac.txt
```
### Example test case:
###### Program:
```sh
# sample program
def main() => int{
    #/this is a
    multi line comment/#
    int a;
    int b;
    # this is a single line comment
    int c;
    if((a>5)) {
        c=((b+a)*a);
    }
    else {
        c=((b+a)-a);
    }
    #this is a single line comment
}
```
###### Output:
- [Lexer Output](https://github.com/durba-s/compiler_project/blob/new/in_lex_out.txt)
- [Parse Stack](https://github.com/durba-s/compiler_project/blob/new/in_out.txt)
- [Three Address code](https://github.com/durba-s/compiler_project/blob/new/in_tac.txt)


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

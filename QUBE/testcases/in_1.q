# Factorial

def fact(int n) => int {
    if(n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

def main() => int{
    
    int x;
    x = 1;
    while( x <= 10 ){
        print(x);
        print(fact(x));
        println();
        x = x + 1;
    }

    return 0;
    
}
# Fibonaccci

def main() => int{
    
    int n;
    input("Enter the value for n: " , n);

    int a = 0 , b = 1;

    if(n == 0)
        print(a);
    elif (n == 1)
        print(b);
    else{
        n -= 2;
        while(n > 0){
            int c = b + a;
            a = b;
            b = c;
            n--;
        }
        print(b);
    }

    return 0;
}
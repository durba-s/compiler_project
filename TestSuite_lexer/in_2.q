# Bubble Sort
def main() => int{
    
    int n;
    input("Enter number of elements: " , n);

    int arr[n];

    print("Enter the elements\n");

    for i in (0,n)
        input(arr[i]);
    
    for i in (0,n)
        for j in (0,n-i-1)
            if(arr[j] > arr[j+1])
                swap(arr[j] , arr[j+1]);
    
    print("Sorted array is: ");

    for i in (0,n)
        print(arr[i] + " ");
    
    return 0;

}
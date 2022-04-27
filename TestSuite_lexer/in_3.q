# Binary Search
def main() => int{
    
    int n;
    input("Enter number of elements: " , n);

    int arr[n];

    print("Enter the elements\n");

    for i in (0,n)
        input(arr[i]);

    int x;
    input("Enter the element to be searched: " , x);

    int l = 0 , h = n - 1;
    bool found = false;
    int pos = -1;

    while(l <= h){
        int mid = (l + h) / 2;
        if(arr[mid] == x){
            found = true;
            pos = mid;
            break;
        }
        if(arr[mid] < x)
            l = mid + 1;
        if(arr[mid] > x)
            h = mid - 1;
    }

    if(found)
        print("Element found at position " + (pos + 1) + "\n");
    else
        print("Element not found\n");

    return 0;
}
//Non-recursive linear search
//A.Harichandana, Roll no-100519733001,CSE Third SEM.
#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Driver code
int main(void)
{
    int n,i,x;
    int arr[50];
    cout<<"No of elements in array: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter element for "<< i<<" position: ";
        cin>>arr[i];
    }
    n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter element to be searched: ";
    cin>>x;

    // Function call
    int result = search(arr, n, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}

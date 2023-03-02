#include<iostream>
#include<climits>

using namespace std;

void print(int input[], int n)
{
    cout<<"Function : "<<sizeof(input)<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<input[i]<<" ";
    }
}

int main()
{
    cout<<"Enter the number of elements : ";

    int n;
    cin>>n;

    int arr[n];

    cout<<"Enter the elements of the array : ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    print(arr,n);

    return 0;
}
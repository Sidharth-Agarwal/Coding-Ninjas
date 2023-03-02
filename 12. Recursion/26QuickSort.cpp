/*

Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 

*/

#include <iostream> 

using namespace std; 

int partitionArray(int input[], int start, int end) 
{
    // Chose pivot 
    int pivot = input[start]; 
    
    // Count elements smaller than pivot and swap 
    int count = 0; 
    
    for (int i = start + 1; i <= end; i++) 
    { 
        if (input[i] <= pivot) 
        { 
            count++; 
        } 
    }
    
    int pivotIndex = start + count;

    int temp = input[start]; 
    input[start] = input[pivotIndex]; 
    input[pivotIndex] = temp; 
    
    // ensure left half contains elements smaller than pivot 
    // and right half larger 
    
    int i = start, j = end; 
    
    while (i <= pivotIndex && j >= pivotIndex) 
    { 
        while (input[i] <= pivot) 
        { 
            i++; 
        } 
        
        while (input[j] > pivot) 
        { 
            j--; 
        } 
        
        if (i < pivotIndex && j > pivotIndex) 
        { 
            int temp = input[i]; 
            input[i] = input[j]; 
            input[j] = temp; 
            i++; 
            j--; 
        } 
    } 
    
    return pivotIndex; 
} 

void quickSort(int input[], int start, int end) 
{ 
    if (start >= end) 
    { 
        return; 
    } 
    
    int pivotIndex = partitionArray(input, start, end); 
    
    quickSort(input, start, pivotIndex - 1); 
    
    quickSort(input, pivotIndex + 1, end); 
} 

void quickSort(int input[], int n) 
{ 
    quickSort(input, 0, n - 1); 
}

int main()
{
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) 
    {
        cin >> input[i];
    }
    
    quickSort(input, n);

    for(int i = 0; i < n; i++) 
    {
        cout << input[i] << " ";
    }
    
    delete [] input;
}

/*

#include <iostream>
#include<algorithm>
using namespace std;
int partition(int *arr,int si,int ei)
{
    int x=arr[si];
    int count_less=0;
    for(int l=si;l<=ei;l++)
    {
        if(arr[l]<x)
        count_less++;
    }
    swap(arr[si],arr[si+count_less]);
    int i=si;
    int j=ei;
    while(i<j)
    {
        if(arr[i]<arr[si+count_less])
        {
            i++;
        }
        else if(arr[j]>=arr[si+count_less])
        {
            j--;
        }
        else
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return si+count_less;
}
void quickSort(int input[], int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
    int c=partition(input,si,ei);
    quickSort(input,si,c-1);
    quickSort(input,c+1,ei);
}
void quickSort(int input[], int size)
{
    quickSort(input, 0, size - 1);
}

*/
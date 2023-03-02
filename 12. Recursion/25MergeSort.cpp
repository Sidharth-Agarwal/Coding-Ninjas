/*

Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 

*/

#include <iostream>

using namespace std;

void merge(int input1[], int size1, int input2[], int size2, int output[]) 
{ 
    int i = 0, j = 0, k = 0; 
    
    while (i < size1 && j < size2) 
    { 
        if (input1[i] < input2[j]) 
        {
            output[k] = input1[i]; 
            k++; 
            i++;
        } 
        
        else 
        { 
            output[k] = input2[j]; 
            j++; 
            k++; 
        } 
    } 
    
    while (i < size1) 
    { 
        output[k] = input1[i]; 
        k++; 
        i++; 
    } 
    
    while (j < size2) 
    { 
        output[k] = input2[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int input[], int size) 
{ 
    if (size <= 1) 
    { 
        return; 
    } 
    
    int mid = size / 2;

    int part1[500], part2[500]; 
    
    int size1 = mid, size2 = size - mid; 
    
    for (int i = 0; i < mid; i++) 
    { 
        part1[i] = input[i]; 
    } 

    int k = 0; 

    for (int i = mid; i < size; i++) 
    { 
        part2[k] = input[i]; 
        k++; 
    } 
    
    mergeSort(part1, size1); 
    mergeSort(part2, size2); 
    
    merge(part1, size1, part2, size2, input); 
}

int main() 
{
    int length;
    cin >> length;

    int* input = new int[length];

    for(int i=0; i < length; i++)
    {
        cin >> input[i];
    }

    mergeSort(input, length);

    for(int i = 0; i < length; i++) 
    {
        cout << input[i] << " ";
    }
}

/*

void merge(int *arr,int si,int mid,int end)
{
        int size1=mid-si+1;
        int size2=end-mid;
        int *local1=new int[size1];
        int *local2=new int[size2];
        for(int i=0;i<size1;i++)
        {
                local1[i]=arr[si+i];
        }
        for(int j=0;j<size2;j++)
        {
                local2[j]=arr[mid+1+j];
        }
		int i=0,j=0,k=si;

        while(i<size1 && j< size2)
        {
            if(local1[i]<=local2[j])
            {
                arr[k]=local1[i];
                i++;
            }
            else
            {
                arr[k]=local2[j];
                j++;
            }
        	k++;
        }
        while(i<size1)
        {
            arr[k]=local1[i];
            k++;
                        i++;
        }
        while(j<size2)
        {
                arr[k]=local2[j];
                        k++;
                        j++;
        }

}

void helper(int arr[],int si,int ei)
{
	if(si>=ei)
    return;
    int mid=(si+ei)/2;
    helper(arr,si,mid);
    helper(arr,mid+1,ei);
    merge(arr,si,mid,ei);

}
void mergeSort(int arr[], int size){
	// Write your code here
   helper(arr,0,size-1);
}

*/

/*

void merge(int input[], int start, int end)
{
    
    int size = end- start +1;
    int sorted[size];
    int mid = (start+end)/2;
    int k = 0;
    int i = start;
    int j = mid+1;
    while(i<= mid && j<= end)
    {
        if(input[i]<=input[j])
        {
            sorted[k] = input[i];
            i++;
            k++;   
        }
          if(input[i]>input[j])
        {
            sorted[k] = input[j];
            j++;
            k++;   
        }
    }
    while(i<=mid)
    {
        sorted[k] = input[i];
        i++;
        k++;
    }
     while(j<=end)
    {
        sorted[k] = input[j];
        j++;
        k++;
    }
    int d = 0;
    for(int i = start; i<=end; i++)
    {
        input[i] = sorted[d++];
    }
}
void mergeSort(int input[], int start, int end)
{
    if(start>= end)
    {
        return;
    }
    int mid = (start+end)/2;
    mergeSort(input,start,mid);
    mergeSort(input,mid+1,end);
    merge(input,start,end);
}



void mergeSort(int input[], int size){
	// Write your code here
       if(size == 0 || size ==1)
           return;
    mergeSort(input,0,size-1);
}

*/
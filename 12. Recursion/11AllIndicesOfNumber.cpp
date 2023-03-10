/*

All Indices of Number
Send Feedback
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. 
Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4

*/

#include<iostream>

using namespace std;

#include<bits/stdc++.h>

void findIndexes(int input[],int currIndex, int size, int x, int output[],int &k) 
{ 
    if(currIndex==size) 
    {
        return;
    }
    
    if(input[currIndex]==x) 
    { 
        output[k]=currIndex; 
        k++; 
    }
    
    findIndexes(input,currIndex+1,size,x,output,k); 
} 

int allIndexes(int input[], int size, int x, int output[]) 
{
    int k=0; 
    
    findIndexes(input,0,size,x,output,k); 
    
    return k; 
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
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);

    for(int i = 0; i < size; i++) 
    {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
}

/*

int allIndexes(int input[],int size,int x,int output[])
{
   	static int index=-1;
    
    if(size==0)
    {
        return 0;
    }
    
    else
    {
        if(input[0]==x)
        {
            output[0]=++index;
            // cout<<index<<" ";
            int smallAns1 = allIndexes(input+1,size-1,x,output+1); // allIndexes(input+1,size-1,x,output+1);
            return smallAns1 + 1; //added
        }

        else
        {
            ++index;
            int smallAns2 = allIndexes(input+1,size-1,x,output);// allIndexes(input+1,size-1,x,output);
        }
	}
}

*/
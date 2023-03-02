#include <iostream>
using namespace std;

void heapSort(int arr[], int n) 
{ 
	// Build the heap in input array
	for (int i = 1; i < n; i++)
	{
		int childIndex = i;
		
		while (childIndex > 0)
		{
			int parentIndex = (childIndex - 1) / 2;
			
			if (arr[childIndex] < arr[parentIndex])
			{ 
				int temp = arr[childIndex];
				arr[childIndex] = arr[parentIndex];
				arr[parentIndex] = temp;
			} 
			
			else
			{
				break;
			}
			
			childIndex = parentIndex;
		}
	}
	
	// Remove elements 
	int size = n;
	
	while (size > 1)
	{ 
		int temp = arr[0];
		arr[0] = arr[size - 1];
		arr[size - 1] = temp;
		size--;
		
		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
		
		while (leftChildIndex < size)
		{ 
			int minIndex = parentIndex;
			
			if (arr[minIndex] > arr[leftChildIndex])
			{ 
				minIndex = leftChildIndex;
			} 
			
			if (rightChildIndx < size && arr[rightChildIndx] < arr[minIndex]) 
			{ 
				minIndex = rightChildIndx; 
			} 
			
			if (minIndex == parentIndex) 
			{ 
				break; 
			} 
			
			int temp = arr[minIndex]; 
			arr[minIndex] = arr[parentIndex]; 
			arr[parentIndex] = temp; 

			parentIndex = minIndex; 
			leftChildIndex = 2 * parentIndex + 1; 
			rightChildIndx = 2 * parentIndex + 2; 
		}
	} 
}

int main() 
{
	int input[] = {5, 1, 2, 0, 8};

	heapSort(input, 5);

	for(int i = 0; i < 5; i++)
	{
		cout << input[i] << " ";
	}

	cout << endl;
}

/*

#include<iostream>
using namespace std;
void heapsort(int arr[],int n)
{
  int i=1;
  while(i<n)
  {
    int childindex=i;
    while (childindex>0) {
      int parentindex=(childindex-1)/2;
      if(arr[parentindex]>arr[childindex])
      {
        int temp=arr[childindex];
      arr[childindex]=arr[parentindex];
      arr[parentindex]=temp;
      }
      else{
        break;
      }
      childindex=parentindex;
    }
    i++;
  }
    int size=n;
    int temp=arr[0];
    arr[0]=arr[size-1];
    arr[size-1]=temp;
    size=size-1;
    while(size>1)
    {
    int parentindex=0;
    int leftchild=2*parentindex+1;
    int rightchild=2*parentindex+2;
    while(leftchild<size)
    {
      int minindex=parentindex;
      if(arr[minindex]>arr[leftchild])
      {
        minindex=leftchild;
      }
      if(arr[minindex]>arr[rightchild]&&rightchild<size)
      {
        minindex=rightchild;
      }
      if(minindex==parentindex)
      break;
      int temp=arr[minindex];
      arr[minindex]=arr[parentindex];
      arr[parentindex]=temp;
      minindex=parentindex;
      leftchild=2*parentindex+1;
      rightchild=2*parentindex+2;
    }
  }
 }
 int main()
 {
   int size;
   cin>>size;
   int *input=new int[size];
   for(int i=0;i<size;i++)
   cin>>input[i];
   heapsort(input,size);
   for(int i=0;i<size;i++)
   cout<<input[i]<<" ";
   //cout<<a<<endl;
   delete[] input;
 }

*/
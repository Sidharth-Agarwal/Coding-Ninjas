#include <iostream>

using namespace std;

int binarySearch(int *input, int n, int val)
{
    //Write your code here
    int first = 0;
    int last = n-1;
    
    int middle = (first+last)/2;
    
    while(first <= last)
    {
        if(input[middle] < val)
        {
            first = middle + 1;
        }
        
        else if(input[middle] == val)
        {
            return middle;
            break;
        }
        
        else
        {
            last = middle - 1;  
        }
        
        middle = (first + last)/2;
    }
    
    if(first > last)
    {
        return -1;
    }
}

int main()
{
    cout<<"Enter the size of the array : ";

	int size;
	cin >> size;
	int *input = new int[size];

    cout<<"Enter the elements of the array : ";

	for(int i = 0; i < size; ++i)
	{
		cin >> input[i];
	}
	
	int val;
	cin >> val;
	cout << binarySearch(input, size, val) << endl;
	
	delete [] input;
	return 0;
}
#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// Minimum Priority Queue

// class MinimumPriorityQueue
// {
//     vector<int> pq;

//     public:

//     MinimumPriorityQueue()
//     {

//     }

//     // Return the size of the priority queue
//     int size()
//     {
//         return pq.size();
//     }

//     // Check if the priority queue is empty or not
//     bool isEmpty()
//     {
//         return pq.size() == 0;
//     }

//     // Get the minimum element from the priority queue
//     int minElement()
//     {
//         if(isEmpty())
//         {
//             return INT_MIN;
//         }

//         return pq[0];
//     }

//     // Insert an element in the priority queue
//     void insert(int element)
//     {
//         pq.push_back(element);

//         int childIndex = pq.size()-1;

//         while(childIndex > 0)
//         {
//             int parentIndex = (childIndex-1)/2;

//             if(pq[childIndex] < pq[parentIndex])
//             {
//                 int temp = pq[childIndex];
//                 pq[childIndex] = pq[parentIndex];
//                 pq[parentIndex] = temp;
//             }

//             else
//             {
//                 break;
//             }

//             childIndex = parentIndex;
//         }
//     }

//     // Remove minimum from the priority queue
//     int removeMin()
//     {
//         if(isEmpty())
//         {
//             return INT_MIN;
//         }

//         int ans = pq[0];
//         pq[0] = pq[(pq.size())-1];
//         pq.pop_back();

//         int parentIndex = 0;
//         int leftChildIndex = (2*parentIndex)+1;
//         int rightChildIndex = (2*parentIndex)+2;

//         while(leftChildIndex < pq.size())
//         {
//             int minIndex = parentIndex;

//             if(pq[leftChildIndex] < pq[minIndex])
//             {
//                 minIndex = leftChildIndex;
//             }

//             if(pq[rightChildIndex] < pq[minIndex] && rightChildIndex < pq.size())
//             {
//                 minIndex = rightChildIndex;
//             }

//             if(parentIndex == minIndex)
//             {
//                 break;
//             }

//             int temp = pq[minIndex];
//             pq[minIndex] = pq[parentIndex];
//             pq[parentIndex] = temp;

//             parentIndex = minIndex;
//             leftChildIndex = (2*parentIndex)+1;
//             rightChildIndex = (2*parentIndex)+2;
//         }

//         return ans;
//     }
// };

// int main()
// {
//     MinimumPriorityQueue p;

// 	p.insert(100);
// 	p.insert(10);
// 	p.insert(15);
// 	p.insert(4);
// 	p.insert(17);
// 	p.insert(21);
// 	p.insert(67);

// 	cout << p.size() << endl;
// 	cout << p.minElement() << endl;

// 	while(!p.isEmpty()) 
// 	{
// 		cout << p.removeMin() << " " ;
// 	}
// 	cout << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Maximum Priority Queue

// class MaximumPriorityQueue
// {
//     vector<int> pq;

//     public:

//     MaximumPriorityQueue()
//     {

//     }

//     // Return the size of the priority queue
//     int size()
//     {
//         return pq.size();
//     }

//     // Check if the priority queue is empty or not
//     bool isEmpty()
//     {
//         return pq.size() == 0;
//     }

//     // Get the maximum element from the priority queue
//     int maxElement()
//     {
//         if(isEmpty())
//         {
//             return INT_MAX;
//         }

//         return pq[0];
//     }

//     // Insert an element in the priority queue
//     void insert(int element)
//     {
//         pq.push_back(element);

//         int childIndex = pq.size()-1;

//         while(childIndex > 0)
//         {
//             int parentIndex = (childIndex-1)/2;

//             if(pq[childIndex] > pq[parentIndex])
//             {
//                 int temp = pq[childIndex];
//                 pq[childIndex] = pq[parentIndex];
//                 pq[parentIndex] = temp;
//             }

//             else
//             {
//                 break;
//             }

//             childIndex = parentIndex;
//         }
//     }

//     // Remove maximum from the priority queue
//     int removeMax()
//     {
//         if(isEmpty())
//         {
//             return INT_MAX;
//         }

//         int ans = pq[0];
//         pq[0] = pq[(pq.size())-1];
//         pq.pop_back();

//         int parentIndex = 0;
//         int leftChildIndex = (2*parentIndex)+1;
//         int rightChildIndex = (2*parentIndex)+2;

//         while(leftChildIndex < pq.size())
//         {
//             int maxIndex = parentIndex;

//             if(pq[leftChildIndex] > pq[maxIndex])
//             {
//                 maxIndex = leftChildIndex;
//             }

//             if(pq[rightChildIndex] > pq[maxIndex] && rightChildIndex < pq.size())
//             {
//                 maxIndex = rightChildIndex;
//             }

//             if(parentIndex == maxIndex)
//             {
//                 break;
//             }

//             int temp = pq[maxIndex];
//             pq[maxIndex] = pq[parentIndex];
//             pq[parentIndex] = temp;

//             parentIndex = maxIndex;
//             leftChildIndex = (2*parentIndex)+1;
//             rightChildIndex = (2*parentIndex)+2;
//         }
        
//         return ans;
//     }
// };

// int main()
// {
//     MaximumPriorityQueue p;

// 	p.insert(100);
// 	p.insert(10);
// 	p.insert(15);
// 	p.insert(4);
// 	p.insert(17);
// 	p.insert(21);
// 	p.insert(67);

// 	cout << p.size() << endl;
// 	cout << p.maxElement() << endl;

// 	while(!p.isEmpty()) 
// 	{
// 		cout << p.removeMax() << " " ;
// 	}
// 	cout << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// In-Place Heap Sort

// void heapSort(int *arr, int n)
// {
//     // Build a heap in the input
//     for(int i=0;i<n;i++)
//     {
//         int childIndex = i;
         
//         while(childIndex > 0)
//         {
//             int parentIndex = (childIndex-1)/2;

//             if(arr[childIndex] < arr[parentIndex])
//             {
//                 int temp = arr[childIndex];
//                 arr[childIndex] = arr[parentIndex];
//                 arr[parentIndex] = temp;
//             }

//             else
//             {
//                 break;
//             }

//             childIndex = parentIndex;
//         }
//     }

//     // Remove elements 
// 	int size = n;
	
// 	while (size > 1)
// 	{ 
// 		int temp = arr[0];
// 		arr[0] = arr[size - 1];
// 		arr[size - 1] = temp;
// 		size--;
		
// 		int parentIndex = 0;
// 		int leftChildIndex = 2 * parentIndex + 1;
// 		int rightChildIndx = 2 * parentIndex + 2;
		
// 		while (leftChildIndex < size)
// 		{ 
// 			int minIndex = parentIndex;
			
// 			if (arr[minIndex] > arr[leftChildIndex])
// 			{ 
// 				minIndex = leftChildIndex;
// 			} 
			
// 			if (rightChildIndx < size && arr[rightChildIndx] < arr[minIndex]) 
// 			{ 
// 				minIndex = rightChildIndx; 
// 			} 
			
// 			if (minIndex == parentIndex) 
// 			{ 
// 				break; 
// 			} 
			
// 			int temp = arr[minIndex]; 
// 			arr[minIndex] = arr[parentIndex]; 
// 			arr[parentIndex] = temp; 

// 			parentIndex = minIndex; 
// 			leftChildIndex = 2 * parentIndex + 1; 
// 			rightChildIndx = 2 * parentIndex + 2; 
// 		}
// 	} 
// }

// int main() 
// {
// 	int input[] = {5, 1, 2, 0, 8};

// 	heapSort(input, 5);

// 	for(int i = 0; i < 5; i++)
// 	{
// 		cout << input[i] << " ";
// 	}

// 	cout << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// In-Built Minimum Priority Queue
	
// int main() {
// 	priority_queue<int> p;

// 	p.push(100);
// 	p.push(21);
// 	p.push(7);
// 	p.push(165);
// 	p.push(78);
// 	p.push(4);
// 	p.push(999);

// 	cout << p.size() << endl;
// 	cout << p.empty() << endl;
// 	cout << p.top() << endl;

// 	while(!p.empty()) {
// 		cout << p.top() << endl;
// 		p.pop();
// 	}
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// In-Built Maximum Priority Queue
	
// int main() {
// 	priority_queue<int, vector<int>, greater<int> > p;

// 	p.push(100);
// 	p.push(21);
// 	p.push(7);
// 	p.push(165);
// 	p.push(78);
// 	p.push(4);

// 	cout << p.size() << endl;
// 	cout << p.empty() << endl;
// 	cout << p.top() << endl;

// 	while(!p.empty()) {
// 		cout << p.top() << endl;
// 		p.pop();
// 	}
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// k-Sorted Array

// void kSortedArray(int *arr, int n, int k)
// {
//     priority_queue<int> pq;

//     for(int i=0;i<k;i++)
//     {
//         pq.push(arr[i]);
//     }

//     int j=0;

//     for(int i=k;i<n;i++)
//     {
//         arr[j] = pq.top();
//         pq.pop();
//         pq.push(arr[i]);
//         j++;
//     }

//     while(!pq.empty())
//     {
//         arr[j] = pq.top();
//         j++;
//         pq.pop();
//     }
// }

// int main()
// {
// 	int input[] = {10, 12, 6, 7, 9};

// 	int k = 3;

// 	kSortedArray(input, 5, k);

// 	for(int i = 0; i < 5; i++) 
// 	{
// 		cout << input[i] << " ";
// 	}
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// k Smallest Elements

// vector<int> kSmallestElements(int *input, int n, int k)
// {
//     priority_queue<int> pq;

//     for(int i=0;i<k;i++)
//     {
//         pq.push(input[i]);
//     }

//     for(int i=k;i<n;i++)
//     {
//         if(input[i] < pq.top())
//         {
//             pq.pop();
//             pq.push(input[i]);
//         }
//     }

//     vector<int> ans;
    
//     while (!pq.empty())
//     {
//         ans.push_back(pq.top());
//         pq.pop();
//     }
    
//     return ans; 
// }

// int main() 
// {
//     int size;
//     cin >> size;

//     int *input = new int[size];

//     for (int i = 0; i < size; i++) 
//     {
//         cin >> input[i];
//     }

//     int k;
//     cin >> k;

//     vector<int> output = kSmallestElements(input, size, k);

//     sort(output.begin(), output.end());

//     for (int i = 0; i < output.size(); i++) 
//     {
//         cout << output[i] << " ";
//     }

//     delete[] input;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// k Largest Elements

// vector<int> kLargestElements(int *input, int n, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> pq;

//     for(int i=0;i<k;i++)
//     {
//         pq.push(input[i]);
//     }

//     for(int i=k;i<n;i++)
//     {
//         if(input[i] > pq.top())
//         {
//             pq.pop();
//             pq.push(input[i]);
//         }
//     }

//     vector<int> ans;

//     while(!pq.empty())
//     {
//         ans.push_back(pq.top());
//         pq.pop();
//     }
    
//     return ans;
// }

// int main() 
// {
	
// 	int size;
// 	cin >> size;
// 	int *input = new int[size];
	
// 	for(int i = 0; i < size; i++)
// 	{
// 		cin >> input[i];
// 	}
    
//     int k;
//     cin >> k;
    
//     vector<int> output = kLargestElements(input, size, k);

//     for(int i = 0; i < output.size(); i++)
//     {
//         cout << output[i] << endl;
//     }
	
// 	return 0;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Check Max Heap

// bool isMaxHeap(int *arr, int n)
// {
//     for(int i=0;i*2+1<n;i++)
//     {
//         int leftChildIndex = 2*i+1;
//         int rightChildIndex = leftChildIndex+1;

//         if(arr[i] < arr[leftChildIndex])
//         {
//             return false;
//         }

//         if(arr[i] < arr[rightChildIndex])
//         {
//             return false;
//         }
//     }

//     return true;
// }

// int main() 
// {
//     int n;
//     cin >> n;
//     int *arr = new int[n];

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

//     delete[] arr;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Kth Largest Element

// int kthLargestElement(int *input, int n, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> pq;

//     for(int i=0;i<k;i++)
//     {
//         pq.push(input[i]);
//     }

//     for(int i=k;i<n;i++)
//     {
//         if(input[i] > pq.top())
//         {
//             pq.pop();
//             pq.push(input[i]);
//         }
//     }

//     return pq.top();
// }

// int main() 
// {
//     int n;
//     cin >> n;

//     int* arr = new int[n];

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int k;
//     cin >> k;

//     cout << kthLargestElement(arr, n, k);

//     delete[] arr;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/


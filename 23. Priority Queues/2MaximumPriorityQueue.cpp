/*

Code : Max Priority Queue
Send Feedback
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.

*/

#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class PriorityQueue
{
    vector<int> pq;

    public:

    PriorityQueue()
    {

    }

    // Check if the queue is empty or not
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    // Get the size of the priority queue - no of elements present
    int getSize()
    {
        return pq.size();
    }

    // Get the maximum element from the priority queue
    int getMax()
    {
        if(isEmpty())
        {
            return INT_MAX;
        }

        return pq[0];
    }

    // Insert element in the priority queue
    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size()-1;

        while(childIndex > 0)
        {
            int parentIndex = (childIndex-1)/2;

            if(pq[childIndex] > pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }

            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    // Delete element from the priority queue
    int removeMax()
    {
        if(isEmpty())
        {
            return INT_MAX;
        }

        int ans = pq[0];
        pq[0] = pq[(pq.size())-1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = (parentIndex*2)+1;
        int rightChildIndex = (parentIndex*2)+2;

        while(leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;

            if(pq[leftChildIndex] > pq[minIndex])
            {
                minIndex = leftChildIndex;
            }

            if(pq[rightChildIndex] > pq[minIndex] && rightChildIndex<pq.size())
            {
                minIndex = rightChildIndex;
            }

            if(parentIndex == minIndex)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2*parentIndex)+1;
            rightChildIndex = (2*parentIndex)+2;
        }

        return ans;
    }
};

int main()
{
    PriorityQueue p;

	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	cout << p.getSize() << endl;
	cout << p.getMax() << endl;

	while(!p.isEmpty()) 
	{
		cout << p.removeMax() << " " ;
	}
	cout << endl;
}
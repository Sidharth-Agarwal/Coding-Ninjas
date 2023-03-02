#include<iostream>
#include<vector>
#include<climits>

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

    // Get the minimum element from the priority queue
    int getMin()
    {
        if(isEmpty())
        {
            return INT_MIN;
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

            if(pq[childIndex] < pq[parentIndex])
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

    // Remove minimum element from the priority queue
    int removeMin()
    {
        if(isEmpty())
        {
            return INT_MIN;
        }

        int ans = pq[0];
        pq[0] = pq[(pq.size())-1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = (2*parentIndex)+1;
        int rightChildIndex = (2*parentIndex)+2;

        while(leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;

            if(pq[leftChildIndex] < pq[minIndex])
            {
                minIndex = leftChildIndex;
            }

            if(pq[rightChildIndex] < pq[minIndex] && rightChildIndex<pq.size())
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
	cout << p.getMin() << endl;

	while(!p.isEmpty()) 
	{
		cout << p.removeMin() << " " ;
	}
	cout << endl;
}
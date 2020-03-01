#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

class MinHeap
{
private:
	int *harr;
	int capacity;
	int heap_size;

public:
	MinHeap(int cap)
	{
		capacity = cap;
		heap_size = 0;
		harr = new int[cap];
	}

	int parent(int i)
	{
		return (i-1)/2;
	}

	int left(int i)
	{
		return 2*i + 1;
	}

	int right(int i)
	{
		return 2*i + 2;
	}

	int getMin()
	{
		return harr[0];
	}

	void MinHeapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int smallest = i;

		if(l < heap_size && harr[smallest] > harr[l])
			smallest = l;
		if(r < heap_size && harr[smallest] > harr[r])
			smallest = r;

		if(smallest != i)
		{
			swap(&harr[smallest], &harr[i]);
			MinHeapify(smallest);
		}
	}

	int extractMin()
	{
		if(heap_size == 0)
			return INT_MAX;
		if(heap_size == 1)
		{
			heap_size--;
			return harr[0];
		}

		int root = harr[0];
		harr[0] = harr[heap_size-1];
		heap_size--;
		MinHeapify(0);

		return root;
	}

	void decreaseKey(int i, int new_val)
	{
		harr[i] = new_val;

		if(i > 0 && harr[i] < harr[parent(i)])
		{
			swap(&harr[i], &harr[parent(i)]);
			i = parent(i);
		}
	}

	void deleteKey(int i)
	{
		decreaseKey(i, INT_MIN);
		extractMin();
	}

	void insertKey(int k)
	{
		if(heap_size == capacity)
		{
			cout << "Overflow!" << endl;
			return;
		}

		heap_size++;
		int i = heap_size-1;
		harr[i] = k;

		if(i > 0 && harr[i] < harr[parent(i)])
		{
			swap(&harr[i], &harr[parent(i)]);
			i = parent(i);
		}
	}
};

int main() 
{ 
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
} 
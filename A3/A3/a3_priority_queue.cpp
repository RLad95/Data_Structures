#include "a3_priority_queue.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int DataType;

PriorityQueue :: PriorityQueue (unsigned int capacity)
{
	capacity_ = capacity;
	size_ = 0;
	heap_ = new DataType(capacity);
}

PriorityQueue::~PriorityQueue()
{
	delete [] heap_;
}

unsigned int PriorityQueue::size() const
{
	return size_;
}

bool PriorityQueue::empty() const
{
	if(size_ == 0)
	{
		return true;
	}
	
	return false;
}

bool PriorityQueue::full() const
{
	if(size_ == capacity_)
	{
		return true;
	}
	
	return false; 
}

void PriorityQueue::print() const
{
	for(int i = 1; i <= size_; i++)
	{
		cout << heap_[i] << endl;
	}
}

DataType PriorityQueue::max() const
{
 	return heap_ [1];
}


bool PriorityQueue::enqueue(DataType val)
{
	if(full())
	{
		return false;
	}
	
	else if(size_ == 0)
	{
		heap_ [1] = val;
		size_ ++;
		return true;		
	}
	else
	{
		int index = size_ + 1;
		int temp;
		heap_[index] = val;
		while(heap_[index] > heap_[index/2] && heap_[1] != val)
		{
			temp = heap_[index];
			heap_[index] = heap_[index/2];
			heap_[index/2] = temp;
			index /= 2; 
		}
		size_ ++;
		return true;
	}
		
}

bool PriorityQueue::dequeue()
{
	if(size_ == 0)
	{
		return false;
	}
	else 
	{
		
		int index = 1;
		int temp;
		heap_[1] = heap_[size_];
		while((heap_[index] < heap_[2*index] || heap_[index] < heap_[2*index+1]) && index < size_ - 1)
		{
			if(heap_[index] < heap_[2*index])
			{
				temp = heap_[index];
				heap_[index] = heap_[index*2];
				heap_[index*2] = temp;
				index *= 2;
						
			}
			else if(heap_[index] < heap_[2*index+1])
			{
				temp = heap_[index];
				heap_[index] = heap_[index*2 + 1];
				heap_[index*2 + 1] = temp;
				index = index*2 +1;	
			}
			
		}
		
		size_--;
		return true; 
	}
	
}



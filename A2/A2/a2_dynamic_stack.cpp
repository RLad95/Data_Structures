#include <iostream>
#include "a2_dynamic_stack.hpp"

using namespace std;

typedef DynamicStack::StackItem StackItem; 
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
	init_capacity_ = 16;
	capacity_ = init_capacity_;
	size_ = 0;
	items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity) {
	init_capacity_ = capacity;
	capacity_ = capacity;
	size_ = 0;
	items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack() {
	delete [] items_;
}

int DynamicStack::size() const {
	return size_;
}

bool DynamicStack::empty() const {
	return size_ == 0;
}

void DynamicStack::print() const {
	for(int i = size_ - 1; i > 0 ; i--)
	{
		cout << items_[i] << endl;
	}
}

StackItem DynamicStack::peek() const {
	if(empty())
		return EMPTY_STACK;
	else
		return items_[size_ - 1];
}

void DynamicStack::push(StackItem value) {
	if(size_ == capacity_)
	{
		capacity_*=2;
		StackItem * temp = new StackItem[capacity_];
		for(int i = 0; i < size_ ; i++)
			temp[i] = items_[i];
		delete [] items_;
		items_ = temp;
	}
	
		items_[size_] = value;
		size_ ++;
	
}

StackItem DynamicStack::pop() {
	if(empty())
		return EMPTY_STACK;
	if( (size_-1 <= capacity_/4 ) && !(capacity_/2 < init_capacity_) )
	{
		capacity_ /= 2;
		StackItem * temp = new StackItem[capacity_];
		for(int i = 0; i < size_ ; i++)
			temp[i] = items_[i];
		delete [] items_;
		items_ = temp;
	}
		size_ --;
		return items_ [size_];
}

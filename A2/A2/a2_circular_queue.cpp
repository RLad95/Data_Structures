#include <iostream>
#include "a2_circular_queue.hpp"
using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
	items_ = new QueueItem[16];
	capacity_ = 16;
	size_ = 0;
	head_ = 0;
	tail_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity) {
	items_ = new QueueItem[capacity];
	capacity_ = capacity;
	size_ = 0;
	head_ = 0;
	tail_ = 0;
}

CircularQueue::~CircularQueue() {
	delete [] items_;
}

int CircularQueue::size() const {  
	return size_;
}

bool CircularQueue::empty() const {    
	return size_ == 0;
}

bool CircularQueue::full() const {
	return size_ == capacity_;
}

void CircularQueue::print() const {
	for(int i = head_; i != tail_; i = (i+1)%capacity_ )
		cout << items_[i] << endl;
}

QueueItem CircularQueue::peek() const {
	if(empty())
		return EMPTY_QUEUE;
	return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
	if(full())
		return false;
	items_[tail_] = value;
	size_++;
	tail_= (tail_ + 1)%capacity_;
	return true;
}

QueueItem CircularQueue::dequeue() {
	if(empty())
		return EMPTY_QUEUE;
	int head = head_;
	head_ = (head_+1)%capacity_;
	size_--;
	return items_[head];
}

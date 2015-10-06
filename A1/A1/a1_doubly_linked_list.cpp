#include "a1_doubly_linked_list.hpp"
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
    value = data;
    next = NULL;
    prev = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
    size_ = 0;
    tail_ = NULL;
    head_ = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
    if (!(head_ == NULL))
    {
        Node* temp = head_;
        while(head_->next != NULL)
        {
            delete temp;
            head_ = head_->next;
            temp = head_;
        }
        head_ = NULL;
        tail_ = NULL;
        temp = NULL;
        size_ = 0;
    }

}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    if (size_ == 0)
        return true;
    return true;
}

bool DoublyLinkedList::full() const
{
    if (size_ == CAPACITY)
        return true;
    return false;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    if (index >= size_)
        return tail_->value;
    
    Node* temp  = head_;
    
    for (int i = 0; i < index; i++)
        temp = temp->next;
    
    return temp->value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    Node* temp = head_;
    for (int i = 0; i < size_; i++)
    {
        if (temp->value == value)
            return i;
        temp = temp->next;
    }
    return size_;
}

void DoublyLinkedList::print() const
{
    Node* temp = head_;
    for (int i = 0; i < size_; i++)
    {
        std::cout << temp->value;
        temp = temp->next;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    Node* temp = head_;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    return temp;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if (index > size_)
        return false;
    
    if (size_ == 0)
    {
        insert_front(value);
        return true;
    }
    else if (index == size_)
    {
        insert_back(value);
        return true;
    }
   
    Node* newNode = new Node(value);
    Node* temp = head_;
    
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;
    newNode->prev = temp;
    newNode->next = temp->next;
    newNode->next->prev = newNode;
    newNode->prev->next = newNode;
    return true;
}

bool DoublyLinkedList::insert_front(DataType value)
{
    if (size_ >= CAPACITY)
        return false;
    
    Node* newNode = new Node(value);
    newNode->next = head_;
    if (head_ == NULL)
    {
        head_ = newNode;
        tail_ = newNode;
    }
    else
    {
        head_->prev = newNode;
        head_ = newNode;
    }
    size_++;
    return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
    if (size_ >= CAPACITY)
        return false;
    
    Node* newNode = new Node(value);
    
    if (head_ == NULL)
    {
        head_ = newNode;
        tail_ = head_;
    }
    else
    {
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
    }
    size_++;
    return true;
    
}

bool DoublyLinkedList::remove(unsigned int index)
{
    if (size_ == 0)
        return false;
    Node* temp = head_;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    size_--;
    return true;
}

bool DoublyLinkedList::remove_front()
{
    if (size_ == 0)
        return false;
    
    Node* temp = head_->next;
    delete temp->prev;
    head_ = temp;
    size_--;
    return true;
}

bool DoublyLinkedList::remove_back()
{
    if (size_ == 0)
        return false;
    
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->next = NULL;
    size_--;
    return true;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if (index >= size_)
        return false;
    
    Node* temp = head_;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    temp->value = value;
    
    return true;
}

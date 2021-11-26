#include "circular-queue.h"
#include <iostream>

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

// default constructor for CircularQueue class
CircularQueue::CircularQueue()
{
    capacity_ = 16;
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}
// parametric constructor for CircularQueue class
CircularQueue::CircularQueue(unsigned int capacity)
{
    capacity_ = capacity;
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}
// deconstructor for CircularQueue class
CircularQueue::~CircularQueue()
{
    for (int i = 0; i < size_; i++) {
        items_[i] = NULL;
    }
    delete[] items_;
}
// outputs whether or not the queue is empty
bool CircularQueue::empty() const
{
    return (size_ == 0);
}
// outputs whether the queue is full
bool CircularQueue::full() const
{
    return (size_ == capacity_);
}
// outputs the current size of the queue
int CircularQueue::size() const
{
    return size_;
}
// adds a queue item to the end of the queue if it is not full
bool CircularQueue::enqueue(QueueItem value)
{
    if (full())
        return false;
    items_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    ++size_;
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue()
{
    if (empty())
        return EMPTY_QUEUE;
    QueueItem value = items_[head_];
    head_ = (head_ + 1) % capacity_;
    --size_;
    return value;
}
// removes the item at the front of the queue and returns it
CircularQueue::QueueItem CircularQueue::peek() const
{
    if (empty())
        return EMPTY_QUEUE;
    return items_[head_];
}
// prints a representation of the queue
void CircularQueue::print() const
{
    for (int i = 0; i < size_; i++) {
        std::cout << "[ " << items_[(head_ + i) % capacity_] << " ]";
        if (i != size_ - 1)
            std::cout << " <- ";
    }
    std::cout << std::endl;
}

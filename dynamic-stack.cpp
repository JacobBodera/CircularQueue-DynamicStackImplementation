#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

// default constructor for the DynamicStack class
DynamicStack::DynamicStack()
{
    init_capacity_ = 16;
    capacity_ = init_capacity_;
    size_ = 0;
    items_ = new StackItem[capacity_];
}
// parametric constructor for the DynamicStack class
DynamicStack::DynamicStack(unsigned int capacity)
{
    init_capacity_ = capacity;
    capacity_ = capacity;
    size_ = 0;
    items_ = new StackItem[capacity_];
}
// deconstructor for the DynamicStack class
DynamicStack::~DynamicStack()
{
    for (int i = 0; i < capacity_; i++){
        items_[i] = NULL;
    }
    delete[] items_;
}
// tests whether the stack is empty
bool DynamicStack::empty() const
{
    return (size_ == 0);
}
// outputs the size of the stack
int DynamicStack::size() const
{
    return size_;
}
// adds a stack item to the top of the stack
void DynamicStack::push(StackItem value)
{
    if (size_ == capacity_) {
        increaseCap(items_);
    }
    items_[size_] = value;
    ++size_;
}
// removes and output the top value of the stack
DynamicStack::StackItem DynamicStack::pop()
{
    if (size_ == 0)
        return EMPTY_STACK;

    else if ((size_ - 1) <= (capacity_ / 4) && (capacity_ / 2) >= init_capacity_)
        decreaseCap(items_);

    --size_;
    return items_[size_];
}
// outputs the top value of the stack
DynamicStack::StackItem DynamicStack::peek() const
{
    if (size_ == 0)
        return EMPTY_STACK;
    return items_[size_ - 1];
}
// prints a visual representation of the stack
void DynamicStack::print() const
{
    for (int i = size_ - 1; i >= 0; i--){
        std::cout << "[ " << items_[i] << " ]" << std::endl;
    }
}
// copies the existing stack into a new stack with a larger/smaller capacity
void DynamicStack::copyToNew(StackItem items, StackItem *newItems)
{
    for (int i = 0; i < size_; i++) {
        newItems[i] = items_[i];
    }
}
// doubles the capacity of the stack to account for adding more values than the existing capacity
void DynamicStack::increaseCap(StackItem *items)
{
    capacity_ *= 2;
    StackItem *newItems = new StackItem[capacity_];
    copyToNew(*items, newItems);
    delete[] items_;
    items_ = newItems;
}
// halves the capacity of the stack when the size is 1/4 the capacity
void DynamicStack::decreaseCap (StackItem *items)
{
    capacity_ /= 2;
    StackItem *newItems = new StackItem[capacity_];
    copyToNew(*items, newItems);
    delete[] items_;
    items_ = newItems;
}
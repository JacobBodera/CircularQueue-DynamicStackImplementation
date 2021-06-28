#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    init_capacity_ = 16;
    capacity_ = init_capacity_;
    size_ = 0;
    items_ = new StackItem[init_capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    size_ = 0;
    capacity_ = capacity;
    items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack()
{
    for (int i = 0; i < capacity_; i++){
        items_[i] = NULL;
    }
    delete []items_;
}

bool DynamicStack::empty() const
{
    return (size_ == 0);
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{

}

DynamicStack::StackItem DynamicStack::pop()
{


}

DynamicStack::StackItem DynamicStack::peek() const
{

}

void DynamicStack::print() const
{

}

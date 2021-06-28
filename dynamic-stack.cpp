#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    init_capacity_ = 16;
    capacity_ = init_capacity_;
    size_ = 0;
    items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    size_ = 0;
    init_capacity_ = capacity;
    capacity_ = capacity;
    items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack()
{
    for (int i = 0; i < capacity_; i++){
        items_[i] = NULL;
    }
    delete[] items_;
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
    if (size_ == capacity_) {
        increaseCap();
    }
    items_[size_] = value;
    ++size_;
}

DynamicStack::StackItem DynamicStack::pop()
{
    if (size_ == 0)
        return EMPTY_STACK;

    else if (size_ < (capacity_ / 4) && (capacity_ / 4) < init_capacity_)
        decreaseCap();

    --size_;
    return items_[size_];
}

DynamicStack::StackItem DynamicStack::peek() const
{
    if (size_ == 0)
        return EMPTY_STACK;
    return items_[size_ - 1];
}

void DynamicStack::print() const
{
    for (int i = 0; i < size_; i++){
        std::cout << "[ " << items_[i] << " ]" << std::endl;
    }
}

void DynamicStack::copyToNew(StackItem items, StackItem *newItems)
{
    for (int i = 0; i < size_; i++) {
        newItems[i] = items_[i];
    }
}

void DynamicStack::increaseCap(StackItem *items)
{
    capacity_ *= 2;
    StackItem *newItems = new StackItem[capacity_];
    copyToNew(*items, newItems);
    delete[] items_;
    items_ = newItems;
}

void DynamicStack::decreaseCap (StackItem *items)
{
    capacity_ /= 2;
    StackItem *newItems = new StackItem[capacity_];
    copyToNew(*items, newItems);
    delete[] items_;
    items_ = newItems;
}
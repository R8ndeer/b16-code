#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T& back()
    {
        // WRITE YOUR CODE HERE
        assert(this->_size >= 1);
        return this->_storage[_tail()];  // use this-> to access the TEMPLATED base class member
    }

    // Const-access the element at the back of the queue
    const T& back() const
    {
        // WRITE YOUR CODE HERE
        assert(this->_size >= 1);
        return this->_storage[_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T& value)
    {
        // WRITE YOUR CODE HERE
        assert(this->_size < this->_storage.size());
        auto index = (this->_position + this->_size + 1) % this->_storage.size();
        this->_storage[index] = value;
        ++this->_size;
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        // WRITE YOUR CODE HERE
        assert(this->_size >= 1);
        this->_position = _tail();
        --this->_size;
    }

    // Remove all elements from the queue
    void clear() 
    { 
        // WRITE YOUR CODE HERE
        this->_position = this->_size = 0;
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        // WRITE YOUR CODE HERE
        return (this->_position + 1) % this->_storage.size();
    }
};

#endif // __queue_enhanced__
#pragma once

#include <iostream>
#include <cstddef>
#include <stdexcept>

namespace sid {
template <typename T>
class vector {
   private:
    T* data_ = nullptr;
    size_t size_;
    size_t capacity_;

    void reallocate() {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < size_; i++) {
            new_data[i] = std::move(data_[i]);
        }

        if (data_) {
            delete[] data_;
        }

        data_ = new_data;
        capacity_ = new_capacity;
    }

   public:

    // ###################################################################
    // Constructors
    
    // Default constructor
    vector() : size_(0), capacity_(0){};
    
    // Constructor with initial capacity
    vector(size_t init_capacity) : size_(0), capacity_(init_capacity) {}

    
    // ###################################################################
    // Rule of 5: destructor, copy constructor, copy assignment operator, move constructor, move assignment operator

    // Destructor
    ~vector() { delete[] data_; }


    // ###################################################################
    // Operators




    // << operator to print the vector
    friend std::ostream& operator<<(std::ostream& os, const vector<T>& rhs) {
        os << "<";
        for (size_t i = 0; i < rhs.size_; ++i) {
            os << rhs.data_[i];
            if (i < rhs.size_ - 1) {
                os << ", ";
            }
        }
        os << ">";
        
        return os;
    }

    // ###################################################################
    // Capacity methods

    // size method to return the number of elements
    size_t size() const { return size_; }

    // capacity method to return the allocated capacity
    size_t capacity() const { return capacity_; }

    // empty method to check if the vector is empty
    bool empty() const { return size_ == 0; }

    // ###################################################################
    // element-access methods

    T at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    // ###################################################################
    // modifier methods

    // push_back method to add an element
    void push_back(const T& value) {
        if (size_ >= capacity_) {
            reallocate();
        }
        data_[size_] = value;
        size_++;
    }

    // pop_back method to remove the last element
    void pop_back() {
        if (size_ > 0) {
            size_--;
        }
    }
};
};  // namespace sid
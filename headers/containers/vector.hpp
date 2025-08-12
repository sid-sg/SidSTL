#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>
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

    void growCapacity(size_t new_capacity) {
        if(new_capacity <= capacity_) return;
        
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

    // Constructor with initial capacity and value
    vector(size_t init_capacity, T init_value) : size_(init_capacity), capacity_(init_capacity) {
        data_ = new T[capacity_];
        for (size_t i = 0; i < init_capacity; i++) {
            data_[i] = init_value;
        }
    }

    // Constructor with initializer list
    vector(std::initializer_list<T> init_list) : size_(init_list.size()), capacity_(init_list.size()) {
        data_ = new T[capacity_];
        size_t i = 0;
        for (const auto& item : init_list) {
            data_[i++] = item;
        }
    }

    // ###################################################################
    // Rule of 5: destructor, copy constructor, copy assignment operator, move constructor, move assignment operator

    // Destructor
    ~vector() { delete[] data_; }

    // Copy constructor
    vector(const vector& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    // Copy assignment operator using copy-and-swap idiom
    vector& operator=(vector rhs) {
        swap(rhs);
        return *this;
    }

    // Move constructor
    vector(vector&& other) noexcept : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
        other.size_ = 0;
        other.capacity_ = 0;
        other.data_ = nullptr;
    }

    // Move assignment
    vector& operator=(vector&& rhs) noexcept {
        if (this != &rhs) {
            delete[] data_;

            size_ = rhs.size_;
            capacity_ = rhs.capacity_;
            data_ = rhs.data_;

            rhs.size_ = 0;
            rhs.capacity_ = 0;
            rhs.data_ = nullptr;
        }
        return *this;
    }

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

    // == operator to compare two vectors
    bool operator==(const vector& rhs) const{
        if (size_ != rhs.size_) {
            return false;
        }
        for (size_t i = 0; i < size_; i++) {
            if (data_[i] != rhs.data_[i]) {
                return false;
            }
        }
        return true;
    }

    // ###################################################################
    // Capacity methods

    // size method to return the number of elements
    size_t size() const { return size_; }

    // capacity method to return the allocated capacity
    size_t capacity() const { return capacity_; }

    // empty method to check if the vector is empty
    bool empty() const { return size_ == 0; }

    // swap method to swap two vectors
    void swap(vector& other) {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }

    // reserve method to change the capacity
    void reserve(size_t new_capacity) {
        growCapacity(new_capacity);
    }

    // resize method to change the size of the vector
    void resize(size_t new_size){
       if(new_size < size_) {
            size_ = new_size;
       }
       else if(new_size > size_) {
            if(new_size > capacity_){
                growCapacity(new_size);               
            }

            for(size_t i = size_; i < new_size; ++i) {
                data_[i] = T();
            }

            size_ = new_size;
       }            
    }

    // resize method to change the size of the vector with a value
    void resize(size_t new_size, const T& value) {
       if(new_size < size_) {
            size_ = new_size;
       }
       else if(new_size > size_) {
            if(new_size > capacity_){
                growCapacity(new_size);               
            }

            for(size_t i = size_; i < new_size; ++i) {
                data_[i] = value;
            }

            size_ = new_size;
       }
    }

    // clear method to remove all elements
    void clear(){
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    // ###################################################################
    // element-access methods

    T at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    T& front() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data_[0];
    }

    T& back() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data_[size_ - 1];
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
    
    // ###################################################################
    // iterators

    using iterator = T*;
    using const_iterator = const T*;

    iterator begin() {
        return data_;
    }

    iterator end() {
        return data_ + size_;
    }

    const_iterator begin() const {
        return data_;
    }

    const_iterator end() const {
        return data_ + size_;
    }

};
};  // namespace sid
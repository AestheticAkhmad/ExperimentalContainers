//
//  Vector.h
//  ContainersExperimental
//
//  Created by Akhmad Oripov  on 10/03/2023.
//

#ifndef Vector_h
#define Vector_h

#include <initializer_list>
#include <algorithm>
#include <memory>
#include <stdexcept>

#include "../Container/Container.h"

namespace expcont {

template<typename T>
class Vector : public Container<T> {
public:
    
    explicit Vector() : Container<T>{}, _data{nullptr}, _end{} {}
    
    explicit Vector(std::size_t size) : Container<T>{size} {
        this->_data = std::make_unique<T[]>(Container<T>::_size);
        this->_end = Container<T>::_size;
    }
    
    explicit Vector(std::initializer_list<T> data) : Container<T>{data.size()} {
        this->_data = std::make_unique<T[]>(Container<T>::_size);
        std::size_t iter{};
        T* rawPtr = this->_data.get();
        std::for_each(data.begin(), data.end(),
            [&iter, this, &rawPtr](const T& value) {
            rawPtr[iter] = value;
            ++iter;
        });
        this->_end= Container<T>::_size;
    }
    
    explicit Vector(std::size_t size, T value) : Container<T>{size} {
        this->_data = std::make_unique<T[]>(Container<T>::_size);
        T* rawPtr{this->_data.get()};
        for(size_t i = 0; i < Container<T>::_size; ++i) {
            rawPtr[i] = value;
        }
        
        this->_end = Container<T>::_size;
    }
    
    T& operator[](std::size_t index) {
        if(index >= this->_end) {
            throw std::out_of_range("Index out of range.\n");
        }
                
        return this->_data.get()[index];
    }
    
    std::size_t size() const noexcept override {
        return this->_end;
    }
    
    bool is_empty() const noexcept override {
        if(this->_end == 0) {
            return true;
        }
        return false;
    }
    
    void push_back(T data) override {
        try {
            
            if(this->is_empty()) {
                Container<T>::_size = 1;
                this->_data = std::make_unique<T[]>(Container<T>::_size);
                this->_data.get()[0] = data;
                this->_end += 1;
                return;
            }
            
            if(this->_end + 1 >= Container<T>::_size) {
                Container<T>::_size *= 2;
                std::unique_ptr<T[]> tempData{std::make_unique<T[]>(Container<T>::_size)};
                
                for(std::size_t i = 0; i < this->_end; ++i) {
                    tempData[i] = this->_data[i];
                }
                
                this->_data.reset(tempData.get());
                this->_data.get()[_end] = data;
                this->_end += 1;
                
                tempData.release();
            } else {
                T* rawPtr{this->_data.get()};
                rawPtr[this->_end] = data;
                this->_end += 1;
            }
            
        } catch(...) {
            return;
        }
    }
    
    T pop_back() override {
        if(this->is_empty() == true) {
            throw std::out_of_range("Pop back on empty vector.");
        } else {
            T poppedElement = this->_data[_end - 1];
            this->_data[this->_end - 1] = 0;
            this->_end -= 1;
            return poppedElement;
        }
    }
    
    void push_front(T data) override {
        try {
            
            if(this->is_empty()) {
                Container<T>::_size = 1;
                this->_data = std::make_unique<T[]>(Container<T>::_size);
                this->_data.get()[0] = data;
                this->_end += 1;
                return;
            }
            
            if(this->_end + 1 >= Container<T>::_size) {
                Container<T>::_size *= 2 + 1;
            }
            
            std::unique_ptr<T[]> tempData{std::make_unique<T[]>(Container<T>::_size)};
            
            for(std::size_t i = 1; i < this->_end; ++i) {
                tempData[i] = this->_data[i - 1];
            }
            
            tempData[this->_end] = this->_data[this->_end - 1];
            
            this->_data.reset(tempData.get());
            this->_data.get()[0] = data;
            this->_end += 1;
            
            tempData.release();
            
        } catch(...) {
            return;
        }
    }
    
    T pop_front() override {
        if(this->is_empty()) {
            throw std::out_of_range("Pop front on empty vector.");
        } else {
            T poppedElement = this->_data.get()[0];
            std::unique_ptr<T[]> tempData{std::make_unique<T[]>(Container<T>::_size)};
            
            for(std::size_t i = 0; i < this->_end - 1; ++i) {
                tempData[i] = this->_data[i + 1];
            }
            
            this->_data.reset(tempData.get());
            this->_end -= 1;
            
            tempData.release();
            
            return poppedElement;
        }
    }
    
    Vector<T>& operator=(Vector<T>& rhs) {
        Container<T>::_size = rhs.size();
        std::unique_ptr<T[]> tempData{std::make_unique<T[]>(Container<T>::_size)};
        
        T* rawPtr{tempData.get()};
        
        for(std::size_t i = 0; i < Container<T>::_size; ++i) {
            rawPtr[i] = rhs[i];
        }
        
        this->_data.reset(rawPtr);
        this->_end = Container<T>::_size;
        tempData.release();
        
        return *this;
    }
    
private:
    std::unique_ptr<T[]> _data;
    std::size_t _end;
};

}


#endif /* Vector_h */

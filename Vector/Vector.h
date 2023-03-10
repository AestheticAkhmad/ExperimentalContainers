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
    
    explicit Vector(std::size_t size) : Container<T>{size} {
        this->_data = std::make_unique<T[]>(Container<T>::_size);
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
    }
    
    explicit Vector(std::size_t size, T value) : Container<T>{size} {
        this->_data = std::make_unique<T[]>(Container<T>::_size);
        T* rawPtr = this->_data.get();
        for(size_t i = 0; i < Container<T>::_size; ++i) {
            rawPtr[i] = value;
        }
    }
    
    T& operator[](std::size_t index) {
        if(index >= Container<T>::_size) {
            throw std::out_of_range("Index out of range.\n");
        }
                
        return this->_data.get()[index];
    }
    
    std::size_t size() const noexcept override {
        return this->_size;
    }
    
    bool isEmpty() const noexcept override {
        if(Container<T>::_size == 0) {
            return true;
        }
        return false;
    }
    
private:
    std::unique_ptr<T[]> _data;
};

}


#endif /* Vector_h */

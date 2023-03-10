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
    
    bool isEmpty() const noexcept override {
        if(Container<T>::_size == 0) {
            return true;
        }
        return false;
    }
    
    void push_back(T data) override {
        try {
            if(_end + 1 >= Container<T>::_size) {
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
                rawPtr[_end] = data;
                this->_end += 1;
            }
            
        } catch(...) {
            return;
        }
    }
    
private:
    std::unique_ptr<T[]> _data;
    std::size_t _end;
};

}


#endif /* Vector_h */

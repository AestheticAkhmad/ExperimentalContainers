//
//  Container.hpp
//  ContainersExperimental
//
//  Created by Akhmad Oripov  on 10/03/2023.
//

#ifndef Container_hpp
#define Container_hpp

#include <iostream>

namespace expcont {

template <typename T>
class Container {
public:
    Container(std::size_t size) : _size{size} {}
    virtual std::size_t size() const noexcept = 0;
    virtual bool isEmpty() const noexcept = 0;
//    virtual auto push_back(T data) const -> void = 0;
protected:
    std::size_t _size;
};

}

#endif /* Container_hpp */

//
//  Container.hpp
//  ContainersExperimental
//
//  Created by Akhmad Oripov  on 10/03/2023.
//

#ifndef Container_hpp
#define Container_hpp



namespace expcont {

template <typename T>
class Container {
public:
    Container() : _size{0} {}
    Container(std::size_t size) : _size{size} {}
    virtual std::size_t size() const noexcept = 0;
    virtual bool is_empty() const noexcept = 0;
    virtual void push_back(T data) = 0;
    virtual T pop_back() = 0;
    virtual void push_front(T data) = 0;
    virtual T pop_front() = 0;
    
protected:
    std::size_t _size;
};

}

#endif /* Container_hpp */

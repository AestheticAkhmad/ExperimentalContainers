//
//  AssociativeContainer.h
//  ContainersExperimental
//
//  Created by Akhmad Oripov  on 15/03/2023.
//

#ifndef AssociativeContainer_h
#define AssociativeContainer_h

template<typename T, typename U = T>
class AssociativeContainer {
public:
    virtual bool insert(T key, U value) = 0;
    virtual bool remove(T key) = 0;
    virtual bool is_empty() const = 0;
    virtual std::size_t size() const = 0;
    std::size_t _size;
}


#endif /* AssociativeContainer_h */

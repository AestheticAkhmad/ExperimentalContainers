//
//  ForwardList.h
//  ContainersExperimental
//
//  Created by Akhmad Oripov  on 11/03/2023.
//

#ifndef ForwardList_h
#define ForwardList_h

#include "../inc_headers.h"


#include "../Container/Container.h"

namespace expcont {

template<typename T>
class ForwardList : public Container<T> {
public:
    
    explicit ForwardList() : Container<T>{}, _head{} {}
    
    explicit ForwardList(std::initializer_list<T> data) : Container<T>{data.size()} {
        this->_head = new Node(*(data.begin() + 0));
        
        std::size_t dataSize{data.size()};
        
        Node* iterNode{this->_head};

        for(std::size_t i = 1; i < dataSize; ++i) {
            iterNode->next = new Node(*(data.begin() + i));
            iterNode = iterNode->next;
        }
        
        this->_tail = iterNode;
    }
    
    std::size_t size() const noexcept {
        return Container<T>::_size;
    }
    
    bool is_empty() const noexcept {
        if(Container<T>::_size == 0) {
            return true;
        }
        return false;
    }
    
    void push_back(T data) {
        try {
            Node* newNode{new Node(data)};
            this->_tail->next = newNode;
            this->_tail = this->_tail->next;

        } catch(...) {
            return;
        }
    }
    
    T pop_back() {
        return {};
    }
    
    void push_front(T data) {}
    
    T pop_front() {return {};}
    
    
    
private:
    struct Node {
        T data;
        Node* next;
        
        Node(T data) : data{data}, next{nullptr} {}
    protected:
        const Node* GetNext() const {
            return next;
        }
    };
    
    Node* _head;
    Node* _tail;
};

}


#endif /* ForwardList_h */

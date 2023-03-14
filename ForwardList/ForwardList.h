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
    
    explicit ForwardList() : Container<T>{}, _head{}, _tail{} {}
    
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
    
    std::size_t size() const noexcept override {
        return Container<T>::_size;
    }
    
    bool is_empty() const noexcept override {
        if(Container<T>::_size == 0) {
            return true;
        }
        return false;
    }
    
    void push_back(T data) override {
        try {
            
            if(this->_head == nullptr) {
                Node* newNode{new Node(data)};
                this->_head = newNode;
                this->_tail = this->_head;
                Container<T>::_size += 1;
                return;
            }
            
            Node* newNode{new Node(data)};
            this->_tail->next = newNode;
            this->_tail = this->_tail->next;
            
            Container<T>::_size += 1;

        } catch(...) {
            return;
        }
    }
    
    T pop_back() override {
        if(this->is_empty()) {
            throw std::out_of_range("Pop back on empty forward list.");
            return {};
        }
        
        if(Container<T>::_size == 1) {
            T data{this->_head->data};
            delete this->_head;
            this->_head = nullptr;
            this->_tail = nullptr;
            Container<T>::_size = 0;
            return data;
        }
        
        Node* iterNode{this->_head};
        
        while(iterNode->next->next != nullptr) {
            iterNode = iterNode->next;
        }
        
        T data{iterNode->next->data};
        delete iterNode->next;
        this->_tail = iterNode;
        this->_tail->next = nullptr;
        
        iterNode = nullptr;
        
        Container<T>::_size -= 1;
        
        return data;
    }
    
    void push_front(T data) override {
        try {
            
            if(this->is_empty()) {
                this->_head = new Node{data};
                this->_tail = this->_head;
                Container<T>::_size += 1;
                return;
            }
            
            Node* newNode{new Node{data}};
            
            newNode->next = this->_head;
            
            this->_head = newNode;
            
            Container<T>::_size += 1;
            
        } catch(...) {
            return;
        }
    }
    
    T pop_front() override {
        if(this->is_empty()) {
            throw std::out_of_range("Pop front on empty forward list.");
            return {};
        }
        
        if(Container<T>::_size == 1) {
            T data{this->_head->data};
            delete this->_head;
            this->_head = nullptr;
            this->_tail = nullptr;
            Container<T>::_size = 0;
            
            return data;
        }
        
        Node* nodeToDelete{this->_head};
        
        T data{nodeToDelete->data};
        
        this->_head = this->_head->next;
        
        delete nodeToDelete;
        nodeToDelete = nullptr;
        
        Container<T>::_size -= 1;
        
        return data;
        
    }
    
    bool remove(T data) {
        if(this->is_empty()) {
            throw std::out_of_range("Removing from empty forward list.");
            return false;
        }
        
        if(Container<T>::_size == 1) {
            if(this->_head->data == data) {
                delete this->_head;
                this->_head = nullptr;
                Container<T>::_size -= 1;
                return true;
            }
            return false;
        }
        
        Node* iterNode{this->_head};
        if(iterNode->data == data) {
            this->_head = this->_head->next;
            delete iterNode;
            iterNode = nullptr;
            Container<T>::_size -= 1;
            return true;
        }
        
        while(iterNode->next != nullptr && iterNode->next->data != data) {
            iterNode = iterNode->next;
        }
        
        Node* nextNode{iterNode->next->next};
        delete iterNode->next;
        iterNode->next = nextNode;
        
        Container<T>::_size -= 1;
        
        return true;
    }
    
    
private:
    struct Node {
        T data;
        Node* next;
        
        Node(T data) : data{data}, next{nullptr} {}
    };
    
    Node* _head;
    Node* _tail;
};

}


#endif /* ForwardList_h */

//
//  main.cpp
//  ContainersExperimental
//
//  Created by Akhmad Oripov  on 10/03/2023.
//

#include <iostream>
#include "Vector/Vector.h"

using namespace std;


int main(int argc, const char * argv[]) {
//    expcont::Vector<int> v{1,2,3,4,5};
//    for(int i = 0; i < 5; ++i) {
//        std::cout<<v[i]<<"\t";
//    }
//    std::cout<<"\n"<<v.size()<<"\n";
//    v.push_back(6);
//    v.push_back(7);
//    v.push_back(8);
//    v.push_back(9);
//
//    v.push_front(0);
//    v.push_front(-1);
//
//    for(int i = 0; i < 11; ++i) {
//        std::cout<<v[i]<<"\t";
//    } std::cout<<std::endl;
//
//    for(int i = 0; i < 9; ++i) {
//        v.pop_back();
//    }
    
    expcont::Vector<int> v;
    cout<<v.size()<<endl;
    for(int i = 0; i < 10; ++i) {
        v.push_front(i);
    }
    
    for(int i = 10; i >= 0; --i) {
        v.push_back(i);
    }
    
    for(int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<"\t";
    } cout<<endl;

    return 0;
}

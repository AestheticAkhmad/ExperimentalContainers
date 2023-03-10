//
//  main.cpp
//  ContainersExperimental
//
//  Created by Akhmad Oripov  on 10/03/2023.
//

#include <iostream>
#include "Vector/Vector.h"


int main(int argc, const char * argv[]) {
    expcont::Vector<int> v{1,2,3,4,5};
    for(int i = 0; i < 5; ++i) {
        std::cout<<v[i]<<"\t";
    }
    std::cout<<"\n"<<v.size()<<"\n";
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    
    for(int i = 0; i < v.size(); ++i) {
        std::cout<<v[i]<<"\t";
    }
    return 0;
}

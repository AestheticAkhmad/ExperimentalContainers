//
//  main.cpp
//  ContainersExperimental
//
//  Created by Akhmad Oripov  on 10/03/2023.
//

#include <iostream>
#include "Vector/Vector.h"


int main(int argc, const char * argv[]) {
    //expcont::Vector<int> v{1,2,3,4,5};
    expcont::Vector<std::string> vs(5, "hello");
    for(int i = 0; i < 5; ++i) {
        std::cout<<vs[i]<<"\t";
    }
    std::cout<<"\n"<<vs.size()<<"\n";
    return 0;
}

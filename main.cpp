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
    expcont::Vector<int> v{1,2,3,4,5};
    
    for(int i = 0; i < 5; ++i) {
        v.pop_front();
    }
    
    cout<<v.size()<<endl;
    


    return 0;
}

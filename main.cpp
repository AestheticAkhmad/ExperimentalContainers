//
//  main.cpp
//  ContainersExperimental
//
//  Created by Akhmad Oripov  on 10/03/2023.
//

#include <iostream>
#include "Vector/Vector.h"
#include "ForwardList/ForwardList.h"

using namespace std;


int main(int argc, const char * argv[]) {

    
    expcont::ForwardList<int> fl{};
    
    for(int i = 0; i < 10; ++i) {
        fl.push_front(10);
    }
    
    cout<<fl.size()<<endl;
    
    for(int i = 0; i < 10; ++i) {
        fl.remove(10);
    }
    
    cout<<fl.size()<<endl;
    
    return 0;
}

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

    
    expcont::ForwardList<int> fl{1,2,3,4,5};;
    cout<<fl.pop_back()<<endl;
    cout<<fl.pop_back()<<endl;
    cout<<fl.pop_back()<<endl;
    cout<<fl.pop_back()<<endl;
    cout<<fl.pop_back()<<endl;
    fl.push_back(10);
    fl.push_back(10);
    fl.push_back(10);
    fl.push_back(10);
    fl.push_back(10);
    fl.push_back(10);
    fl.push_back(10);
    cout<<fl.pop_front()<<endl;
    cout<<fl.pop_front()<<endl;
    cout<<fl.pop_front()<<endl;
    cout<<fl.pop_front()<<endl;
    cout<<fl.pop_front()<<endl;
    cout<<fl.pop_front()<<endl;
    cout<<fl.pop_front()<<endl;
    
    cout<<fl.size()<<endl;
    
    
    
    
    return 0;
}

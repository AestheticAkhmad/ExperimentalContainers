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
//    expcont::Vector<int> v{1,2,3,4,5};
//    expcont::Vector<int> g{5,7,8,9,10,11,12};
//
//    for(int i = 0; i < g.size(); ++i) {
//        cout<<g[i]<<"\t";
//    } cout<<endl;
//
//    g = v;
//
//    for(int i = 0; i < g.size(); ++i) {
//        cout<<g[i]<<"\t";
//    } cout<<endl;
//
//    cout<<v.size()<<endl;
    
    expcont::ForwardList<int> fl{1,2,3,4,5};
    fl.pop_back();
    cout<<fl.size()<<endl;
    
    return 0;
}

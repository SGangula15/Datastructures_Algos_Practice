//
//  utilityFunctions.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/18/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

//using STL
void adjacentFinder()
{
    std::vector<int> v1{0, 1, 2, 3, 40, 40, 41, 41, 5};
 
    auto i1 = std::adjacent_find(v1.begin(), v1.end());
 
    if (i1 == v1.end()) {
        std::cout << "no matching adjacent elements\n";
    } else {
        std::cout << "the first adjacent pair of equal elements at: "
                  << std::distance(v1.begin(), i1) << '\n';
    }
 
    auto i2 = std::adjacent_find(v1.begin(), v1.end(), std::greater<int>());
    if (i2 == v1.end()) {
        std::cout << "The entire vector is sorted in ascending order\n";
    } else {
        std::cout << "The last element in the non-decreasing subsequence is at: "
                  << std::distance(v1.begin(), i2) << '\n';
    }
}

void printList(const std::vector<int>& list){
    std::cout << "List is:\t";
    
    // insert code here...
    
    //add integer to the front end
    //list.push_front(25);
    
    //add integer to the back end
    //list.push_back(13);
    
    //auto iterate = std::find(list.begin(), list.end(), 5);
    
    
    //if(iterate != list.end()){
    //    list.insert(iterate, 32);
    //}

//    for(int n:list){
//        std::cout << n<< '\t';
//    }
    for_each(begin(list), end(list),[](auto const& value){cout<<value<<"\t";});
    
    std::cout << '\n';
}


//    //maximum value in the vector with STL
//    std::cout<<"\nMaximum of vectlist is:"<<*max_element(vectlist.begin(), vectlist.end())<<std::endl;
//    std::cout<<"Min\tMax"<<std::endl;
//    for(size_t vectsize=0; vectsize < vectlist.size(); ++vectsize){
//        std::cout<<min(vectsize, vectlist.size()) <<"\t"<< max(vectsize,vectlist.size())<<std::endl;
//    }

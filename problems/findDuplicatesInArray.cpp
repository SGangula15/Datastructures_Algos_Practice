//
//  findDuplicatesInArray.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/18/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

void findDuplicatesInArray(const std::vector<int>& vectlist){
    //START: Find repeted element in array 0< element < n, n <= arraysize
    if(vectlist.size()==0 || vectlist.size()==1)
        throw invalid_argument("Getting a profit requires at least 2 prices");
    
    std::vector<int> repeatedElementsInArray;
    //copy vector
    std::vector<int> findDuplicate(vectlist);
    printList(vectlist);
    //printList(findDuplicate);
    for(int index=0; index<findDuplicate.size();index++){
        if(findDuplicate[abs(findDuplicate[index])] >=0)
            findDuplicate[abs(findDuplicate[index])]= -findDuplicate[abs(findDuplicate[index])];
        else
            repeatedElementsInArray.push_back(abs(findDuplicate[index]));
    }
    std::cout<<"Repeating elements are: ";
    for(size_t index = 0; index < repeatedElementsInArray.size(); index++){
        std::cout<<repeatedElementsInArray[index]<<"\t";
    }//END: Find repeted element in array 0< element < n, n <= arraysize
}

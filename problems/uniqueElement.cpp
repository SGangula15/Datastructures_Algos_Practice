//
//  uniqueElement.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/19/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

int uniqueElement(string arr){
    
    //build hash map
    size_t n = arr.size();
    unordered_map<char, int> charCount;
    cout<<"char"<<"\t"<<"count\n";
    for(int ch=0; ch<n; ch++){
        ++charCount[arr[ch]];
        cout<<arr[ch] <<"\t\t"<<charCount[arr[ch]]<<"\n";
    }
    
    for(int ch=0; ch<n; ch++){
        if(charCount[arr[ch]] == 1)
            return ch;
    }
    return -1;
}

//
//  productArrayPuzzle.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/18/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

using namespace std;

vector<int> productOfArrayExceptItself(vector<int>& array){
    const int n = static_cast<int>(array.size());
    vector<int> productOfIndexArray(n);
    vector<int> leftProductArray(n,1);
    vector<int> rightProductArray(n,1);
    
    for(auto i=1;i<n;++i){
        leftProductArray[i] = leftProductArray[i-1]*array[i-1];
    }
    
    for(auto i= n-2; i>=0 ; --i){
        rightProductArray[i] = rightProductArray[i+1] * array[i+1];
    }
    
    for(auto i=0;i<n;i++){
        productOfIndexArray[i] = leftProductArray[i]*rightProductArray[i];
    }
    
    cout<<"\nProduct of elements is: ";
    for(auto element:productOfIndexArray){
        cout<<"\t"<<element;
    }
    
    return productOfIndexArray;
}

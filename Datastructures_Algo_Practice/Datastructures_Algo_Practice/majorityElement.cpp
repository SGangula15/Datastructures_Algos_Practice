//
//  majorityElement.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/18/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

int majorityElement(vector<int> array){
    
    unordered_map<int, int> map;
    if(array.size()==1){
        cout<<"Majority element is: "<<array[0]<<endl;
        return array[0];
    }
    
    if(array.size()>1){
        for(int i=0; i < array.size(); i++){
            if(++map[array[i]] > array.size()/2)
                return array[i];
        }
    }
    return -1;
}

int majorityElementOptimised(vector<int> array){
    
    int currentCandidate = 0;
    int counter = 0;
    for(auto element:array){
        if(counter == 0){
            currentCandidate = element;
            counter++;
        }
        
        if(counter > 0){
            if(element == currentCandidate)
                counter++;
            else
                counter--;
        }
    }
    
    return currentCandidate;
}

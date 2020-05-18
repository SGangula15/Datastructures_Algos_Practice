//
//  search.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/18/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

bool binraySearch(int target, const vector<int>& nums){
    // floor index
    //ceiling index
    
    size_t floorIndex = 0;
    size_t ceilingIndex = nums.size();
    
    while(floorIndex < ceilingIndex)
    {
        size_t distance = ceilingIndex - floorIndex;
        size_t halfDistance = distance/2;
        size_t guessIndex = floorIndex + halfDistance;
        
        int guessValue = nums[guessIndex];
        
        if(guessValue == target){
            return true;
        }
        
        if(guessValue > target){
            ceilingIndex = guessIndex;
        }
        
        else
        {
            floorIndex = guessIndex+1;
        }
    }
    return false;
}

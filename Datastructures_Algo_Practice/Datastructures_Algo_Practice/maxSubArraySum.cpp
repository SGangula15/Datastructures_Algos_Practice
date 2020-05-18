//
//  maxSubArraySum.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/18/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

int maxSubArraySumWIndeces(vector<int> arr) {
    //kadane's algorithm
    //Kadane says - maxsubarray sum could be either the
    // 1-element at current index  OR
    // 2-element at current index + sum upto previous index
    //\note - sum upto prev index is added only if it is the maximum sum upto previous index you have seen so far, so
    //\sum upto previous index should be max(sum to previous index)
    // in nutshell maxSubarraySum = max(element at current index, max(sum upto previous index))
    
    int start = 0;
    int end = 0;
  
    int maxSoFar = 0, maxEndingHere = 0;
    //maxEndingHere is the maximum at the current index
    //example: arr =[-2, 1, 4, 3, 2] at index 1
    //maxEndingHere is max(1 , 1+(-2) ) = 1
  
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > maxEndingHere + arr[i]) {
            start = i;
            maxEndingHere = arr[i];
        } else
            maxEndingHere = maxEndingHere + arr[i];
  
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            end = i;
        }
    }
    std::cout<<"Found Maximum subarray sum between index "<<start<<" and "<< end <<" is: "<<maxSoFar<<std::endl;
    return maxSoFar;
}

int kadanesMaxSumAlgo(vector<int> arr) {
    //kadane's algorithm
    //Kadane says - maxsubarray sum could be either the
    // 1-element at current index  OR
    // 2-element at current index + sum upto previous index
    //\note - sum upto prev index is added only if it is the maximum sum upto previous index you have seen so far, so
    //\sum upto previous index should be max(sum to previous index)
    // in nutshell maxSubarraySum = max(element at current index, max(sum upto previous index))
  
    int maxSoFar = arr[0], maxEndingHere = arr[0];
    //maxEndingHere is the maximum at the current index
    //example: arr =[-2, 1, 4, 3, 2] at index 1
    //maxEndingHere is max(1 , 1+(-2) ) = 1
  
    for (int i = 1; i < arr.size(); i++) {
//        if (arr[i] > maxEndingHere + arr[i]) {
//            start = i;
//            maxEndingHere = arr[i];
//        } else
//            maxEndingHere = maxEndingHere + arr[i];
//
//        if (maxSoFar < maxEndingHere) {
//            maxSoFar = maxEndingHere;
//            end = i;
//        }
        maxEndingHere = max(arr[i], maxEndingHere+arr[i]);
        maxSoFar      = max(maxSoFar, maxEndingHere);
    }
    std::cout<<"Maximum subarray sum is: "<<maxSoFar<<std::endl;
    return maxSoFar;
}

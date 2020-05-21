//
//  twoSum.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/20/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

vector<int> twoSum(vector<int>& arr, int target){
    printList(arr);
    unordered_map<int, bool> map;
    vector<int> result(2);
    size_t n = arr.size();
    for(int i=0; i < n; i++){
        int diff = target - arr[i];
        if(map[diff]){
            result[0] = i;
            result[1] = map[diff];
            cout<<"target = "<<arr[result[0]]<<" + "<<arr[result[1]]<<endl;
            return result;
        }
        map[arr[i]] = true;
    }
    cout<<"target sum not found"<<endl;
    return {-1,-1};
}

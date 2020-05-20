//
//  utilityHeader.hpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/18/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#ifndef utilityHeader_hpp
#define utilityHeader_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <cstdlib>
#include <functional>
#include <string>
#include <unordered_map>

using namespace std;

bool binraySearch(int target, const vector <int>& nums);
void mergeSort(vector<int>& vectorToSort);
void adjacentFinder(void);
void printList(const std::vector<int>& list);
void findDuplicatesInArray(const std::vector<int>& list);
int fibonacciRecursion(int n);
int fibonacciOptimised(int n);
int maxSubArraySumWIndeces(vector<int> array);
int kadanesMaxSumAlgo(vector<int> arr);
int majorityElement(vector<int> array);
int majorityElementOptimised(vector<int> array);
int uniqueElement(string arr);
vector<int> productOfArrayExceptItself(vector<int>& array);


#endif /* utilityHeader_hpp */

//
//  main.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/17/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <cstdlib>
#include <functional>
#include <unordered_map>

using namespace std;

bool binraySearch(int target, const vector <int>& nums);
void mergeSort(vector<int>& vectorToSort);
void adjacentFinder(void);
void printList(const std::vector<int>& list);
void printDuplicatesInArray(const std::vector<int>& list);
int fibonacciRecursion(int n);
int fibonacciOptimised(int n);
int maxSubArraySumWIndeces(vector<int> array);
int kadanesMaxSumAlgo(vector<int> arr);
int majorityElement(vector<int> array);

class Fibber
{
private:
    unordered_map<int, int> memo_;

public:
    int fib(int n)
    {
        if (n < 0) {
            throw invalid_argument(
                "Index was negative. No such thing as a negative index in a series.");
        }

        // base cases
        else if (n == 0 || n == 1) {
            return n;
        }

        // see if we've already calculated this
        auto it = memo_.find(n);
        if (it != memo_.end()) {
            cout << "grabbing memo[" << n << "]" << endl;
            return it->second;
        }

        cout << "computing fib(" << n << ")" << endl;
        int result = fib(n - 1) + fib(n - 2);

        // memoize
        memo_.insert(make_pair(n, result));

        return result;
    }
};


int main(int argc, const char* argv[]) {
    //const char* path = "/Users/srikanthgangula/desktop/Helloworld/Linkedlist/example.txt";
    //ofstream myfile(path);
    //myfile.open ("example.txt");
    //myfile << "Writing this to a file.\n";
    //myfile.close();
   
    std::cout << "Hello, World!\n";
    
    //recursion
    int series = fibonacciOptimised(0);
    std::cout<<"fib series is "<<series<<std::endl;
    series = fibonacciOptimised(2);
    std::cout<<"fib series is "<<series<<std::endl;
    //dynamic programming
    //Fibber* fibonacci = new Fibber();
    //fibonacci->fib(3);
    
    std::cout<< numeric_limits<int>::max()<<std::endl;
    // insert code here...
    std::vector<int> vectlist = {1, 2, 2, 2, -3, 2, 2, 1};
    printDuplicatesInArray(vectlist);
    std::cout<<std::endl;
    std::cout<<"Majoirty element is: "<<majorityElement(vectlist)<< std::endl;
    maxSubArraySumWIndeces(vectlist);
    kadanesMaxSumAlgo(vectlist);

    // maximum value in the vector
    std::cout<<"\nMaximum of vectlist is:"<<*max_element(vectlist.begin(), vectlist.end())<<std::endl;
//    std::cout<<"Min\tMax"<<std::endl;
//    for(size_t vectsize=0; vectsize < vectlist.size(); ++vectsize){
//        std::cout<<min(vectsize, vectlist.size()) <<"\t"<< max(vectsize,vectlist.size())<<std::endl;
//    }
    
    //add integer to the front end
    vectlist.push_back(25);
    //add integer to the back end
    vectlist.push_back(35);
    auto viterate = std::find(vectlist.begin(), vectlist.end(), 5);
    if(viterate != vectlist.end()){
        vectlist.insert(viterate, 4);
    }
    
    vectlist.insert(viterate+4, 14);
    
    mergeSort(vectlist);
    std::cout<<"Merge sorting done: ";
    for(int n:vectlist){
        std::cout << n << '\t';
    }
    
    bool targetFound = binraySearch(25, vectlist);
    std::cout << "\nTarget found? = " << targetFound  << endl;
    std::cout << '\n';
    
    adjacentFinder();
    
    return 0;
}


void mergeSort(vector<int>& vectorToSort)
{
    // BASE CASE: arrays with fewer than 2 elements are sorted
    if (vectorToSort.size() < 2) {
        return;
    }

    // STEP 1: divide the array in half
    // we use integer division, so we'll never get a "half index"
    size_t midIndex = vectorToSort.size() / 2;

    vector<int> left(vectorToSort.begin(), vectorToSort.begin() + midIndex);
    vector<int> right(vectorToSort.begin() + midIndex, vectorToSort.end());

    // STEP 2: sort each half
    mergeSort(left);
    mergeSort(right);

    // STEP 3: merge the sorted halves
    size_t currentLeftIndex  = 0;
    size_t currentRightIndex = 0;

    for (size_t currentSortedIndex = 0; currentSortedIndex < vectorToSort.size();
            ++currentSortedIndex) {

        // sortedLeft's first element comes next
        // if it's less than sortedRight's first
        // element or if sortedRight is exhausted
        if(currentLeftIndex < left.size() &&
           (currentRightIndex >= right.size() || left[currentLeftIndex] < right[currentRightIndex])){
            vectorToSort[currentSortedIndex] = left[currentLeftIndex];
            ++currentLeftIndex;
        }
        else {
            vectorToSort[currentSortedIndex] = right[currentRightIndex];
            ++currentRightIndex;
        }
    }
}

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

void printDuplicatesInArray(const std::vector<int>& vectlist){
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

int fibonacciRecursion(int n)
{
    //std::cout<<"recursion start index in this loop is ("<< n<<")" <<std::endl;
    if (n < 0) {
        throw invalid_argument(
            "Index was negative. No such thing as a negative index in a series.");
    }

    // base cases
    if (n == 0 || n == 1) {
    //    std::cout<<"current index at rec ("<< n<<")" <<std::endl;
        cout << "*computing fib rec(" << n << ")" << endl;

        return n;
    }

    cout << "computing fib rec(" << n << ")" << endl;
    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

int fibonacciOptimised(int n)
{
    //std::cout<<"recursion start index in this loop is ("<< n<<")" <<std::endl;
    if (n < 0) {
        throw invalid_argument(
            "Index was negative. No such thing as a negative index in a series.");
    }
        
        int previousTwo[] = {0,1};
        int counter = 3;
        while(counter <= n){
            int nextFib = previousTwo[0] + previousTwo[1];
            previousTwo[0] = previousTwo[1];
            previousTwo[1] = nextFib;
            counter++;
        }
    return n > 1? previousTwo[1] : previousTwo[0];
}

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

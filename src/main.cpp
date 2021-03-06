//
//  main.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/17/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//
#include "utilityHeader.hpp"

using namespace std;

int main(int argc, const char* argv[]) {
    //const char* path = "/Users/srikanthgangula/desktop/Helloworld/Linkedlist/example.txt";
    //ofstream myfile(path);
    //myfile.open ("example.txt");
    //myfile << "Writing this to a file.\n";
    //myfile.close();
    std::vector<int> vectlist = {1, 2, -3, 4, 5, 6, 8};
    std::vector<std::vector<int>> vectOfVect {
                                              {1,   3,  5,  7},
                                              {10, 11, 16, 20},
                                              {23, 30, 34, 50}
                                              };
    twoSum(vectlist, 7);
    searchSortedMatrix(vectOfVect, 30);
    //uniqueElement("Coddiing");
    std::cout << "Hello, World!\n";
    std::cout<< "Numerical limit, max is: "<<numeric_limits<int>::max()<<std::endl;
    // insert code here...
    findDuplicatesInArray(vectlist);
    std::cout<<"\nMajoirty element is: "<<majorityElement(vectlist)<< std::endl;
    int majorityOptimised = majorityElementOptimised(vectlist);
    std::cout<<"Majoirty(optimised) element is: "<<majorityOptimised<< std::endl;
    maxSubArraySumWIndeces(vectlist);
    kadanesMaxSumAlgo(vectlist);
    
    return 0;
}



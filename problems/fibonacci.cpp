//
//  fibonacciOptimised.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/18/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

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

//
//  searchSortedMatrix.cpp
//  Datastructures_Algo_Practice
//
//  Created by Srikanth Gangula on 5/20/20.
//  Copyright © 2020 Srikanth Gangula. All rights reserved.
//

#include "utilityHeader.hpp"

bool searchSortedMatrix(vector<vector<int>>& matrix, int target) {
    
    size_t row = 0;
    size_t col = matrix[0].size() - 1;
    cout<<"Given matrix has "<<matrix.size()<<" rows and "<<matrix[0].size()<<" columns"<<endl;
    while(row < matrix.size() && col >= 0){
        if(matrix[row][col] < target)
            row =row+1;
        else if(matrix[row][col] > target)
            col =col-1;
        else{
            cout<<"Target is found in matrix at row:"<<row<<" and column:"<<col<<endl;
            return 1;
        }
    }
    cout<<"Target is not found in matrix :("<<endl;
    return 0;
}

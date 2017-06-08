//
//  main.cpp
//  Array-SearchInaSortedMatrix
//
//  Created by George Jolly on 6/7/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
 
    
    vector<int> matrix[4];
    
    matrix[0].push_back(5);
    matrix[0].push_back(7);
    matrix[0].push_back(8);
    matrix[0].push_back(9);
    
    matrix[1].push_back(6);
    matrix[1].push_back(9);
    matrix[1].push_back(11);
    matrix[1].push_back(13);
    
    matrix[2].push_back(7);
    matrix[2].push_back(11);
    matrix[2].push_back(12);
    matrix[2].push_back(14);
    
    matrix[3].push_back(8);
    matrix[3].push_back(13);
    matrix[3].push_back(16);
    matrix[3].push_back(17);
    
    int nRow = 4;
    int nCol = matrix[0].size();
    
    
    int i = 0;
    int j = nCol - 1;
    
    int nSearch = 13;
    bool bFound = false;
    
    while( i < nRow && j >= 0  )
    {
        
        if( nSearch == matrix[i][j])
        {
            std::cout << "NUmber found at row = " << i << " and col = " << j << std::endl;
            bFound = true;
            break;
        }
        else if( nSearch < matrix[i][j])
        {
            --j;
        }
        else
        {
            ++i;
        }
    }
    
    if( !bFound )
    {
        std::cout << "Could not find the number..\n";
    }
    
    return 0;
}

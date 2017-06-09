//
//  main.cpp
//  matrix_rotation
//
//  Created by George Jolly on 3/19/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    vector<int> Matrix[2];
    
    Matrix[0].push_back(1);
    Matrix[0].push_back(2);
    
    Matrix[1].push_back(3);
    Matrix[1].push_back(4);
    
    
    for( int i = 0 ; i < 2 ; ++i )
    {
        for( int j = 0 ; j < 2 ; ++j )
        {
            std::cout << Matrix[i][j] << "\t";
        }
        
        std::cout << std::endl;
    }
    
    // Swap the rows.
    int i = 0;
    int j = 1;
    
    while( i < j )
    {
        Matrix[i].swap(Matrix[j]);
        --j;
        ++i;
    }
    
    std::cout << std::endl;
    
 
    // Swap diagonals.[i][j] and [j][i]
    for( int i = 0 ; i < 2 ; ++i )
    {
        for( int j = i + 1 ; j < 2 ; ++j )
        {
            int tmp = Matrix[i][j];
            Matrix[i][j] = Matrix[j][i];
            Matrix[j][i] = tmp;
        }
    }
    
    
    for( int i = 0 ; i < 2 ; ++i )
    {
        for( int j = 0 ; j < 2 ; ++j )
        {
            std::cout << Matrix[i][j] << "\t";
        }
        
        std::cout << std::endl;
    }
    
    

    

    

    
    return 0;
}

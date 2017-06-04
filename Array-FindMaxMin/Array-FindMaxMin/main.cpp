//
//  main.cpp
//  Array-FindMaxMin
//
//  Created by George Jolly on 6/3/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {

    vector<int> Array;
    
    int max = INT_MIN;
    int min = INT_MAX;
    
    Array.push_back(4);
    Array.push_back(3);
    Array.push_back(5);
    Array.push_back(1);
    Array.push_back(2);
    Array.push_back(6);
    Array.push_back(9);
    Array.push_back(2);
    Array.push_back(10);
    Array.push_back(11);
    
    // std::cout << Array.size() << std::endl;
    
    for( int i = 0 ; i < Array.size()/2; ++i )
    {
        int x = i*2;
        int y = i*2 + 1;
        
        if( Array[x] > Array[y] )
        {
            if( max < Array[x])
            {
                max = Array[x];
            }
            
            if( min > Array[y] )
            {
                min = Array[y];
            }
        }
        else
        {
            if( max < Array[y])
            {
                max = Array[y];
            }
            
            if( min > Array[x] )
            {
                min = Array[x];
            }

        }
        
        // std::cout << x << "," << y << std::endl;
    }
    
    std::cout << "min = " << min << ", max = " << max << std::endl;
    
    return 0;
}

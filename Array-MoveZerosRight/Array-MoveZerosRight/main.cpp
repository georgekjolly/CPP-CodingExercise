//
//  main.cpp
//  Array-MoveZerosRight
//
//  Created by George Jolly on 6/3/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int k[] = { 0, 5, 0, 2, 3, 0, 3, 5, 0 };
    
    int i = 0;
    int j = i + 1;
    
    int nLen = sizeof(k)/sizeof(int);
    
    while( i < nLen && j < nLen )
    {
        if( k[i] == 0 && k[j] != 0 )
        {
            int tmp = k[i];
            k[i] = k[j];
            k[j] = tmp;
            
            ++i;
            ++j;
        }
        
        if( k[i] == 0 && k[j] == 0 )
        {
            ++j;
        }
    }
    
    for( int x = 0 ; x < nLen ; ++x )
    {
        std::cout << k[x] << "\t";
    }
    
    std::cout << std::endl;
    
    
    
    return 0;
}

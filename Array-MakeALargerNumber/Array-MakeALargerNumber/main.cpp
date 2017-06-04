//
//  main.cpp
//  Array-MakeALargerNumber
//
//  Created by George Jolly on 6/3/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int compare (const void * a, const void * b)
{
    return ( *(char*)a - *(char*)b );
}

int main(int argc, const char * argv[]) {
    
    char ch[] = "3784"; //3874
    int nLen = ( sizeof(ch) / sizeof(char)) - 1;
    
    bool found = false;
    int j_global = 0;
    int i_global = 0;
    for( int i = nLen - 1 ; i >= 0 ; --i )
    {
        found = false;
        for( int j = i -1 ; j >= 0 ; --j )
        {
            if( ch[j] < ch[i] )
            {
                j_global = j;
                i_global = i;
                std::cout << "j = " << j << " i = " << i << std::endl;
                found = true;
                break;
            }
            else
            {
                found = false;
                break;
            }
        }
        
        if( found )
            break;
    }
    
    if( found )
    {
        // swap
        char tmp = ch[j_global];
        ch[j_global] = ch[i_global];
        ch[i_global] = tmp;
        
        // do sort from i_global
        qsort( &ch[i_global], (nLen - 1)  - i_global + 1, sizeof(char), compare);
        
        std::cout << "Largerst number = " << ch << std::endl;
    }
    else
    {
        std::cout << "Unable to find the largest number\n";
    }
    
    return 0;
}

//
//  main.cpp
//  StringOperation
//
//  Created by George Jolly on 6/8/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str[] = {"ryan", "dog", "sam", "nyar", "mas", "god" };
    string dup[] = {"ryan", "dog", "sam", "nyar", "mas", "god" };
    int idx[] = {0,1,2,3,4,5};

    int nLen = sizeof(dup) / sizeof(dup[0]);
    

    for( int i = 0 ; i < nLen ; ++i )
    {
        std::sort( dup[i].begin(), dup[i].end());
        //std::cout << dup[i] << std::endl ;
    }
    
    
    for( int i = 0 ; i < nLen; ++i )
    {
        for( int j = i + 1; j < nLen; ++j )
        {
                if( dup[i] < dup[j])
                {
                    string tmp = dup[i];
                    dup[i] = dup[j];
                    dup[j] = tmp;
                    
                    int tmp1 = idx[i];
                    idx[i] = idx[j];
                    idx[j] = tmp1;
                }
        }
    }
    
    for( int i = 0 ; i < nLen ; ++i )
    {
        std::cout << str[idx[i]] << std::endl ;
    }

    return 0;
}

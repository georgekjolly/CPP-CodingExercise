//
//  main.cpp
//  Array-LargestSumSubArray
//
//  Created by George Jolly on 6/3/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>




int main(int argc, const char * argv[]) {
 

    //int arr[] = { 4, 3, -5, 0, 6, -8, 12, 3, -9, 2, 5, 8, -3, 4, 8, 0, 3, -3, -5, -9, 4, 2 };
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int nLen = sizeof(arr)/sizeof(int);
    
    int nSum = 0;
    int gMax = INT_MIN;
    int nI = 0;
    int nJ = 0;
    for( int i = 0 ; i < nLen ; ++i )
    {
        nSum = nSum + arr[i];
        
        if( nSum <= 0 )
        {
            nSum = 0;
            nI = i+1;
            continue;
        }
        
        if( gMax < nSum )
        {
            gMax = nSum;
            nJ = i;
        }
        
    }
    
    std::cout << nI << " " << nJ << " gmax = "<< gMax << std::endl;;
    
    
    
    return 0;
}

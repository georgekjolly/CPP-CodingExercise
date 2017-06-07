//
//  main.cpp
//  Heap-maxheap
//
//  Created by George Jolly on 6/7/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void minHeap( int nRootIdx, vector<int>& Array, int nSize )
{
    if( nRootIdx > nSize  )
    {
        return;
    }
    
    int nRootNode = Array[nRootIdx];
    int nLNode = Array[ 2*nRootIdx];
    int nRNode = Array[ 2*nRootIdx + 1 ];
    
    if( nLNode < nRNode )
    {
        if( nRootNode > nLNode )
        {
            // swap
            int nTmp = nLNode;
            Array[2*nRootIdx] = nRootNode;
            Array[nRootIdx] = nTmp;
            
            minHeap( 2*nRootIdx, Array, nSize);
        }
    }
    else
    {
        if( nRootNode > nRNode )
        {
            // swap
            int nTmp = nRNode;
            Array[2*nRootIdx + 1] = nRootNode;
            Array[nRootIdx] = nTmp;
            
            minHeap( 2*nRootIdx + 1, Array, nSize);
        }
        
    }
    
    
}



void maxHeap( int nRootIdx, vector<int>& Array, int nSize )
{
    if( nRootIdx >= nSize  )
    {
        return;
    }
    
    int nRootNode = Array[nRootIdx];
    int nLNode = Array[ 2*nRootIdx];
    int nRNode = Array[ 2*nRootIdx + 1 ];
    
    if( nLNode > nRNode )
    {
        if( nRootNode < nLNode )
        {
            // swap
            int nTmp = nLNode;
            Array[2*nRootIdx] = nRootNode;
            Array[nRootIdx] = nTmp;
            
            maxHeap( 2*nRootIdx, Array, nSize);
        }
    }
    else
    {
        if( nRootNode < nRNode )
        {
            // swap
            int nTmp = nRNode;
            Array[2*nRootIdx + 1] = nRootNode;
            Array[nRootIdx] = nTmp;
            
            maxHeap( 2*nRootIdx + 1, Array, nSize);
        }

    }
    
    
}

bool getVal( vector<int>& Array, int& nVal_o )
{
    if( Array.size() > 1 )
    {
        nVal_o = Array[1];
        
        int nLastIdx = Array.size()-1;
        Array[1] = Array[nLastIdx];
        
        Array.pop_back();
        
        for( int i = nLastIdx/2 ; i >= 1 ; --i )
        {
            maxHeap( i, Array, nLastIdx/2 );
        }
        
        return true;
    }
    nVal_o = 0;
    return false;
    
}

int main(int argc, const char * argv[]) {
 
    
    int Array[6] = {0,4,7,8,5,2};
    
    vector<int> myVec;
    myVec.push_back(0);
    myVec.push_back(4);
    myVec.push_back(7);
    myVec.push_back(8);
    myVec.push_back(5);
    myVec.push_back(2);
    
    
    
    // int nLen = (sizeof(Array)/sizeof(int))-1;
    int nLen = myVec.size() - 1;
    
    // Max heap.
    std::cout << "Max heap....\n";
    for( int i = nLen/2 ; i >= 1 ; --i )
    {
        maxHeap( i, myVec, nLen/2 );
    }
    
    for( int i = 1 ; i <= nLen; ++i )
    {
        std::cout << myVec[i] << std::endl;
    }
    
    
    // Getting the values.
    int nVal = 0;
    getVal( myVec, nVal );
    std::cout << "Value retreived is = " << nVal << std::endl;
    
    getVal( myVec, nVal );
    std::cout << "Value retreived is = " << nVal << std::endl;
    
    getVal( myVec, nVal );
    std::cout << "Value retreived is = " << nVal << std::endl;
    
    getVal( myVec, nVal );
    std::cout << "Value retreived is = " << nVal << std::endl;
    
    
    // Min heap
    nLen = myVec.size() - 1;
    std::cout << "\nMin heap....\n";
    for( int i = nLen/2 ; i >= 1 ; --i )
    {
        minHeap( i, myVec, nLen/2 );
    }
    
    for( int i = 1 ; i <= nLen; ++i )
    {
        std::cout << myVec[i] << std::endl;
    }

    return 0;
}

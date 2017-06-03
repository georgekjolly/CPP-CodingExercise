//
//  main.cpp
//  BTree_Max_Sum_Path_Negetive
//
//  Created by George Jolly on 6/3/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>

using namespace std;

class BTree
{
public:
    
    BTree( int nData ) : m_nData( nData),pRight(0),pLeft(0)
    {
        
    }
    
    
    static int FindMaxSum( BTree* pRoot )
    {
        if( pRoot == 0 ) return 0;
        
        if( pRoot->pRight == 0 && pRoot->pLeft == 0 ) return pRoot->m_nData;
        
        int nLData = FindMaxSum( pRoot->pLeft );
        int nRData = FindMaxSum( pRoot->pRight );
        
        if( m_nMaxSum < nLData )
            m_nMaxSum = nLData;
        if( m_nMaxSum < nRData )
            m_nMaxSum = nRData;
        
        if( m_nMaxSum <  ( nLData + nRData + pRoot->m_nData ))
            m_nMaxSum = nLData + nRData + pRoot->m_nData;
        
        
        return  max( nLData, nRData ) + pRoot->m_nData;
        
    }
    
    
    
    
    
    
public:
    
    int m_nData;
    BTree* pRight;
    BTree* pLeft;
    
    static int m_nMaxSum;
};

int BTree::m_nMaxSum = 0;

int main(int argc, const char * argv[]) {

    
    BTree* pFive = new BTree(5);
    BTree* pSix = new BTree(-6);
    BTree* pOne = new BTree(1);
    BTree* pEight = new BTree(8);
    BTree* pTwo = new BTree(2);
    
    pFive->pLeft = pSix;
    pFive->pRight = pOne;
    
    pSix->pLeft = pEight;
    pSix->pRight = pTwo;
    
    BTree::FindMaxSum( pFive );
    
    std::cout << "Max sum = " << BTree::m_nMaxSum << std::endl;
    
    return 0;
}

//
//  main.cpp
//  BTree_MaxSum_Path_Positive
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
        
        int nLData = FindMaxSum(pRoot->pLeft);
        int nRData = FindMaxSum(pRoot->pRight);
        
        if(( nLData + nRData + pRoot->m_nData ) > m_nSum )
            m_nSum = nLData + nRData + pRoot->m_nData;
        
        return ( max( nLData, nRData ) + pRoot->m_nData );
    }
    
    
    
    
    
public:
    
    int m_nData;
    BTree* pRight;
    BTree* pLeft;
    
    static int m_nSum;
    
};

int BTree::m_nSum = 0;



int main(int argc, const char * argv[]) {

    
    BTree* pFive = new BTree(5);
    BTree* pSix = new BTree(6);
    BTree* pOne = new BTree(1);
    BTree* pEight = new BTree(8);
    BTree* pTwo = new BTree(2);
    
    pFive->pLeft = pSix;
    pFive->pRight = pOne;
    
    pSix->pLeft = pEight;
    pSix->pRight = pTwo;
    
    BTree::FindMaxSum(pFive);
    
    std::cout << "Max sum = " << BTree::m_nSum << std::endl;
    
    return 0;
}

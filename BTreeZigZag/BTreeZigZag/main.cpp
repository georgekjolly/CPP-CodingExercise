//
//  main.cpp
//  BTreeZigZag
//
//  Created by George Jolly on 5/29/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>

class BTree
{
public:
    
    BTree( int nData ) : m_nData(nData), pLeft(0), pRight(0)
    {
    
    }
    
    
    static int getMaxLevel( BTree* pRoot )
    {
        if( pRoot == 0 )
            return 0;
            
        if( pRoot->pRight == 0 && pRoot->pLeft == 0)
        {
            return 1;
        }
        
        int nLeft = getMaxLevel( pRoot->pLeft );
        int nRight = getMaxLevel( pRoot->pRight );
        
        return ( std::max( nLeft, nRight ) + 1 );
    }
    
    
    static void printZigZag( BTree* pRoot, int nLevel, bool bReverse )
    {
        if( pRoot == 0 )
            return;
        
        if( nLevel == 0 )
        {
            std::cout << pRoot->m_nData << "\t";
            return;
        }
        
        if( bReverse )
        {
            printZigZag( pRoot->pLeft, nLevel - 1, bReverse );
            printZigZag( pRoot->pRight, nLevel - 1, bReverse );
        }
        else
        {
            printZigZag( pRoot->pRight, nLevel - 1, bReverse );
            printZigZag( pRoot->pLeft, nLevel - 1, bReverse );
        }
    }
    
    
public:
    
    int m_nData;
    BTree* pLeft;
    BTree* pRight;
};


int main(int argc, const char * argv[]) {
    
    BTree* pOne = new BTree(1);
    BTree* pTwo = new BTree(2);
    BTree* pThree = new BTree(3);
    BTree* pFour = new BTree(4);
    BTree* pFive = new BTree(5);
    BTree* pSix = new BTree(6);
    BTree* pSeven = new BTree(7);
    
    
    pOne->pLeft = pTwo;
    pOne->pRight = pThree;
    
    pTwo->pLeft = pSeven;
    pTwo->pRight = pSix;
    
    pThree->pLeft = pFive;
    pThree->pRight = pFour;
    
    int nLevel = BTree::getMaxLevel( pOne );
    
    std::cout << "Level = " << nLevel << std::endl;
    
    for( int i = 0 ; i < nLevel ; ++i )
    {
        bool bRevers = true;
        if( i % 2 )
        {
            bRevers = true;
        }
        else
        {
            bRevers = false;
        }
        BTree::printZigZag(pOne, i, bRevers );
        std::cout << "\n";
    }
    
    
    return 0;
}

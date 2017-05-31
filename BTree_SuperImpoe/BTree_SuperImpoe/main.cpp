//
//  main.cpp
//  BTree_SuperImpoe
//
//  Created by George Jolly on 5/31/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>

class BTree
{
public:
    
    BTree( int nData ) : m_nData( nData ), pLeft(0), pRight(0)
    {
    
    }
    
    
    static int getMaxDepth( BTree* pRoot )
    {
        if( pRoot == 0 )
            return 0;
        
        if( pRoot->pLeft ==0 && pRoot->pRight == 0 )
            return 1;
        
        int nL = getMaxDepth( pRoot->pLeft );
        int nR = getMaxDepth( pRoot->pRight );
        
        return (std::max( nL, nR ) + 1);
    }
    
    static void printNodes( BTree* pFive, int nLevel )
    {
        if( pFive == 0 )
            return;
        
        if( nLevel == 0 )
        {
            std::cout << pFive->m_nData << "\t";
        }
        
        printNodes(pFive->pLeft, nLevel - 1 );
        printNodes(pFive->pRight, nLevel - 1 );
    }
    
    static BTree* superImpose( BTree* pFirst, BTree* pSecond )
    {
        if( pFirst == 0 && pSecond == 0 )
        {
            return NULL;
        }
        
        if( pFirst == 0 )
            return pSecond;
        
        if( pSecond == 0 )
            return pFirst;
        
        pFirst->pLeft = superImpose( pFirst->pLeft, pSecond->pLeft );
        pFirst->pRight = superImpose( pFirst->pRight, pSecond->pRight );
        
        return pFirst;
    }

    
    
    
public:

    int m_nData;
    BTree* pLeft;
    BTree* pRight;
    
};

int main(int argc, const char * argv[]) {
  
    BTree* pFive1 = new BTree(5);
    BTree* pSix1 = new BTree(6);
    BTree* pOne1 = new BTree(1);
    BTree* pEight1 = new BTree(8);
    BTree* pTwo1 = new BTree(2);
    
    pFive1->pLeft = pSix1;
    pFive1->pRight = pOne1;
    
    pSix1->pLeft = pEight1;
    pSix1->pRight = pTwo1;
    
    int nDepth = BTree::getMaxDepth( pFive1 );
    
    std::cout << "Depth = " << nDepth << "\n\n";
    
    std::cout << "BFS\n";
    
    for( int i = 0 ; i < nDepth ; ++i )
    {
        BTree::printNodes( pFive1, i );
        std::cout << "\n";
    }
    
    
    BTree* pOne2 = new BTree(1);
    BTree* pTwo2 = new BTree(2);
    BTree* pThree2 = new BTree(3);
    BTree* pFour2 = new BTree(4);
    BTree* pFive2 = new BTree(5);
    
    pOne2->pLeft = pTwo2;
    pOne2->pRight = pThree2;
    
    pThree2->pLeft = pFour2;
    pThree2->pRight = pFive2;
    
    nDepth = BTree::getMaxDepth( pOne2 );
    
    std::cout << "Depth = " << nDepth << "\n\n";
    
    std::cout << "BFS\n";
    
    for( int i = 0 ; i < nDepth ; ++i )
    {
        BTree::printNodes( pOne2, i );
        std::cout << "\n";
    }
    
    BTree* pRoot = BTree::superImpose( pFive1, pOne2 );
    
    
    nDepth = BTree::getMaxDepth( pRoot );
    
    std::cout << "Depth = " << nDepth << "\n\n";
    
    std::cout << "BFS\n";
    
    for( int i = 0 ; i < nDepth ; ++i )
    {
        BTree::printNodes( pRoot, i );
        std::cout << "\n";
    }


    
    return 0;
}

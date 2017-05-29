//
//  main.cpp
//  BTreeSumOfChildNodes
//
//  Created by George Jolly on 5/29/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>

using namespace std;

class BTree
{
public:
    
    BTree( int nData ) : m_nData( nData ), pRight(0), pLeft(0)
    {
    
    }
    
    static void dfs( BTree* pRoot )
    {
        if(pRoot == 0 )
            return;
        
        std::cout << pRoot->m_nData << "\t";
            
        dfs( pRoot->pLeft );
        dfs( pRoot->pRight );
    }
    
    static int sumChildNodes( BTree* pRoot )
    {
        if( pRoot == 0 )
            return 0;
            
        if( pRoot->pRight == 0 && pRoot->pLeft == 0 )
        {
            return pRoot->m_nData;
        }
        
        
        int nNode1 = sumChildNodes( pRoot->pLeft );
        int nNode2 = sumChildNodes( pRoot->pRight );
        
        int nTmp = pRoot->m_nData;
        
        pRoot->m_nData = nNode1 + nNode2;
        
        return (nTmp + nNode1 + nNode2);
    }
    
    
public:
    
    int m_nData;
    BTree* pRight;
    BTree* pLeft;

};

int main(int argc, const char * argv[]) {
 
    BTree* pOne = new BTree(1);
    BTree* pTwo = new BTree(2);
    BTree* pThree = new BTree(3);
    BTree* pFour = new BTree(4);
    BTree* pFive = new BTree(5);
    BTree* pSix = new BTree(6);
    BTree* pSeven = new BTree(7);
    BTree* pEight = new BTree(8);
    
    
    pOne->pLeft = pTwo;
    pOne->pRight = pThree;
    
    pTwo->pLeft = pFour;
    pTwo->pRight = pFive;
    
    pThree->pLeft = pEight;
    
    pEight->pLeft = pSix;
    pEight->pRight = pSeven;
    
    BTree::dfs( pOne );
    
    std::cout << std::endl;
    
    BTree::sumChildNodes( pOne );
    
    BTree::dfs( pOne );
    std::cout << std::endl;
    
    return 0;
}

//
//  main.cpp
//  BST_Insertion_order_maintained
//
//  Created by George Jolly on 6/3/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>


using namespace std;

class BSTree
{
public:
    
    BSTree( int nData ) : m_nData( nData),pRight(0),pLeft(0), pNext(0)
    {
        
    }
    
    static void inorder( BSTree* pRoot )
    {
        if( pRoot == 0 ) return;
        
        inorder( pRoot->pLeft);
        
        std::cout << pRoot->m_nData << "\t";
        
        inorder(pRoot->pRight);
    }
    

    static BSTree* AddNode( BSTree* pRoot, int nData )
    {
        BSTree* pCurrent = pRoot;
        
        if( pCurrent == 0 )
        {
            return new BSTree( nData );
        }
        
        BSTree* pTmp = 0;
        while ( pCurrent )
        {
            pTmp = pCurrent;
            if( nData <= pCurrent->m_nData )
            {
                pCurrent = pCurrent->pLeft;
            }
            else
            {
                pCurrent = pCurrent->pRight;
            }
        }
        
        BSTree* pNewNode = new BSTree(nData);
        
        if( nData <= pTmp->m_nData)
        {
            pTmp->pLeft = pNewNode;
        }
        else
        {
            pTmp->pRight = pNewNode;
        }
        
        pCurrent = pRoot;
        pTmp = 0;
        while( pCurrent )
        {
            pTmp = pCurrent;
            pCurrent = pCurrent->pNext;
        }
        
        pTmp->pNext = pNewNode;
        
        return pRoot;
    }
    
    
    static void getInsertedOrder( BSTree* pRoot )
    {
        while( pRoot )
        {
            std::cout << pRoot->m_nData << "\t";
            pRoot = pRoot->pNext;
        }
    }
    
    
public:
    
    int m_nData;
    BSTree* pRight;
    BSTree* pLeft;
    BSTree* pNext;
    
    static int m_nMaxSum;
};


int main(int argc, const char * argv[]) {

    
    BSTree* pRoot = BSTree::AddNode(0, 5);
    pRoot = BSTree::AddNode(pRoot, 1);
    pRoot = BSTree::AddNode(pRoot, 2);
    pRoot = BSTree::AddNode(pRoot, 6);
    pRoot = BSTree::AddNode(pRoot, 8);
    
    BSTree::inorder(pRoot);
    
    std::cout << std::endl;
    
    BSTree::getInsertedOrder( pRoot );
    
    std::cout << std::endl;
    
    return 0;
}

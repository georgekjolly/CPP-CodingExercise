//
//  main.cpp
//  IsBST
//
//  Created by George Jolly on 5/30/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>

class BSTree
{
public:
    
    BSTree( int nData ) : m_nData( nData ),
    pRight(0),
    pLeft(0)
    {
        
    }
    
    
    static BSTree* Add( BSTree* pRoot, int nData )
    {
        if( pRoot == 0 )
        {
            return (new BSTree( nData ));
        }
        if( nData <= pRoot->m_nData)
        {
            pRoot->pLeft = Add( pRoot->pLeft, nData );
        }
        else
        {
            pRoot->pRight = Add( pRoot->pRight, nData );
        }
        
        return  pRoot;
    }
    
    
    static void inorder( BSTree* pRoot )
    {
        if( pRoot == 0 )
            return;
        
        inorder( pRoot->pLeft );
        std::cout << pRoot->m_nData << "\t";
        inorder( pRoot->pRight );
    }

    
    
    static bool IsBST( BSTree* pRoot )
    {
        if( pRoot == 0 )
            return true;
        
        static BSTree* pPrev = 0;
        
        if( false == IsBST( pRoot->pLeft ))
        {
            return false;
        }
        
        if( pPrev )
        {
            if( pPrev->m_nData > pRoot->m_nData )
                return false;
        }
        pPrev = pRoot;
        
        if( false == IsBST( pRoot->pRight ))
        {
            return false;
        }
        
        return true;
    }

    
    
public:
    
    int m_nData;
    BSTree* pRight;
    BSTree* pLeft;
    
};



int main(int argc, const char * argv[]) {

    BSTree* pRoot = new BSTree( 50 );
    
    pRoot = BSTree::Add( pRoot, 40 );
    pRoot = BSTree::Add( pRoot, 30 );
    pRoot = BSTree::Add( pRoot, 45 );
    pRoot = BSTree::Add( pRoot, 60 );
    
    std::cout << "Inorder..\n";
    BSTree::inorder( pRoot );
    std::cout << "\n";
    
    std::cout << "Binary Tree is = " << BSTree::IsBST(pRoot) << std::endl;
    
    BSTree* pFive = new BSTree(5);
    BSTree* pSix = new BSTree(6);
    BSTree* pOne = new BSTree(1);
    BSTree* pEight = new BSTree(8);
    BSTree* pTwo = new BSTree(2);
    
    pFive->pLeft = pSix;
    pFive->pRight = pOne;
    
    pSix->pLeft = pEight;
    pSix->pRight = pTwo;
    
    std::cout << "Binary Tree is = " << BSTree::IsBST(pFive) << std::endl;
    
    return 0;
}

//
//  main.cpp
//  BST_Kth_Smallest
//
//  Created by George Jolly on 6/3/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>


using namespace std;

class BSTree
{
public:
    
    BSTree( int nData ) : m_nData( nData),pRight(0),pLeft(0)
    {
        
    }
    
    static void inorder( BSTree* pRoot )
    {
        if( pRoot == 0 ) return;
        
        inorder( pRoot->pLeft);
        
        std::cout << pRoot->m_nData << "\t";
        
        inorder(pRoot->pRight);
    }

    static bool FindKthSmallest( BSTree* pRoot, int k )
    {
        if( pRoot == 0 ) return false;
        
        static int kcntr = 1;
        
        if( FindKthSmallest( pRoot->pLeft, k)) return true;
        
        if( kcntr == k )
        {
            std::cout << k << "th smallest element = " << pRoot->m_nData << std::endl;
            return true;
        }
        
        ++kcntr;
        
        if( FindKthSmallest(pRoot->pRight, k)) return true;
        
        return false;
    }

    
public:
    
    int m_nData;
    BSTree* pRight;
    BSTree* pLeft;
    
    static int m_nMaxSum;
};


int main(int argc, const char * argv[]) {

    BSTree* pFive = new BSTree(5);
    BSTree* pSix = new BSTree(6);
    BSTree* pOne = new BSTree(1);
    BSTree* pEight = new BSTree(8);
    BSTree* pTwo = new BSTree(2);
    
    pFive->pLeft = pOne;
    pFive->pRight = pSix;
    
    pOne->pRight = pTwo;
    pSix->pRight = pEight;
    
    BSTree::inorder(pFive);
    
    std::cout << "\n";
    
    BSTree::FindKthSmallest(pFive,4);
    
    std::cout << std::endl;
    
    return 0;
}

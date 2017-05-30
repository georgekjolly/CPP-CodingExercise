//
//  main.cpp
//  BTreeToSLL
//
//  Created by George Jolly on 5/30/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class SLL
{
public:
    
    SLL( int nData ) : m_nData(nData), pNext(0)
    {
        
    }
    
    int m_nData;
    SLL* pNext;
};


class DLL
{
public:
    
    DLL( int nData ) : m_nData(nData), pNext(0), pPrev(0)
    {
        
    }
    
    int m_nData;
    DLL* pPrev;
    DLL* pNext;
};


class BTree
{
public:
    
    BTree( int nData ) : m_nData( nData ),
    pRight(0),
    pLeft(0)
    {
        
    }
    
    
    static void inorderSLL( BTree* pRoot, SLL** pSLL )
    {
        if( pRoot == 0 ) return;
        
        inorderSLL( pRoot->pLeft, pSLL );
        
        // std::cout << pRoot->m_nData << "\t";
        if(*pSLL == 0 )
        {
            *pSLL = new SLL(pRoot->m_nData);
        }
        else
        {
            SLL* pNode = *pSLL;
            SLL* pTmp = 0;
            while( pNode )
            {
                pTmp = pNode;
                pNode = pNode->pNext;
            }
            
            pTmp->pNext = new SLL( pRoot->m_nData );
        }
        
        inorderSLL( pRoot->pRight, pSLL );
    }
    
    
    static void inorderDLL( BTree* pRoot, DLL** pDLL )
    {
        if( pRoot == 0 ) return;
        
        inorderDLL( pRoot->pLeft, pDLL );
        
        // std::cout << pRoot->m_nData << "\t";
        if(*pDLL == 0 )
        {
            *pDLL = new DLL(pRoot->m_nData);
        }
        else
        {
            DLL* pNode = *pDLL;
            DLL* pTmp = 0;
            while( pNode )
            {
                pTmp = pNode;
                pNode = pNode->pNext;
            }
            
            DLL* newDLL = new DLL( pRoot->m_nData );
            pTmp->pNext = newDLL;
            newDLL->pPrev = pTmp;
        }
        
        inorderDLL( pRoot->pRight, pDLL );
    }
    
    
    
public:
    
    int m_nData;
    BTree* pRight;
    BTree* pLeft;
    
};


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
    
    SLL* pRoot = 0;
    BTree::inorderSLL( pFive, &pRoot );
    
    std::cout << endl;
    
    std::cout << "Single link list printing...\n";
    while( pRoot )
    {
        std::cout << pRoot->m_nData << "\t";
        pRoot = pRoot->pNext;
    }
   
    DLL* pDLLRoot = 0;
    BTree::inorderDLL( pFive, &pDLLRoot );
    
    std::cout << endl;
    
    std::cout << "Doubly link list printing...\n";
    while( pDLLRoot )
    {
        std::cout << pDLLRoot->m_nData << "\t";
        pDLLRoot = pDLLRoot->pNext;
    }

    std::cout << std::endl;
    
    return 0;
}

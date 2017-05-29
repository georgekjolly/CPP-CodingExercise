//
//  main.cpp
//  BTreeLCA
//
//  Created by George Jolly on 5/29/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class BTreeLCA
{
public:
    
    BTreeLCA( int nData ) : m_nData( nData ),
                            pRight(0),
                            pLeft(0)
    {
        
    }
    
    
    static void inorder( BTreeLCA* pRoot )
    {
        if( pRoot == 0 ) return;
    
        inorder( pRoot->pLeft );
        std::cout << pRoot->m_nData << "\t";
        inorder( pRoot->pRight );
    }
    
    static bool searchNode( BTreeLCA* pRoot , BTreeLCA* pFindNode, vector<BTreeLCA*>& NodeVector )
    {
        if( pRoot == 0 )
            return false;
        
        NodeVector.push_back(pRoot);
        
        if( pRoot == pFindNode )
        {
            return true;
        }
        
        if( searchNode(pRoot->pLeft, pFindNode,  NodeVector )) return true;
        if( searchNode(pRoot->pRight, pFindNode, NodeVector )) return true;
        
        NodeVector.pop_back();
        
        return false;
    }

    
public:
    
    int m_nData;
    BTreeLCA* pRight;
    BTreeLCA* pLeft;
    
};


int main(int argc, const char * argv[]) {

    
    BTreeLCA* pFive = new BTreeLCA(5);
    BTreeLCA* pSix = new BTreeLCA(6);
    BTreeLCA* pOne = new BTreeLCA(1);
    BTreeLCA* pEight = new BTreeLCA(8);
    BTreeLCA* pTwo = new BTreeLCA(2);
    
    pFive->pLeft = pSix;
    pFive->pRight = pOne;
    
    pSix->pLeft = pEight;
    pSix->pRight = pTwo;
    

    BTreeLCA::inorder( pFive );
    
    vector<BTreeLCA*> firstVector;
    if(!BTreeLCA::searchNode( pFive, pOne, firstVector ))
    {
        std::cout << "First not found returning..\n";
        return 0;
    }
    
    std::cout << std::endl;
    
    // Printing the path
    for( int i = 0; i < firstVector.size(); ++i )
    {
        std::cout << firstVector[i]->m_nData << "\t";
    }
    
    vector<BTreeLCA*> secVector;
    if( !BTreeLCA::searchNode( pFive, pFive, secVector ))
    {
        std::cout << "Second not found returning..\n";
        return 0;
    }
    
    std::cout << std::endl;
    
    // Printing the path
    for( int i = 0; i < secVector.size(); ++i )
    {
        std::cout << secVector[i]->m_nData << "\t";
    }

    std::cout << std::endl;
    
    // find the ancestor
    
    int k = 0;
    
    for( int i = 0, j = 0 ; i < firstVector.size() && j < secVector.size() ; ++i, ++j )
    {
        if( firstVector[i] != secVector[j] )
        {
            k = i;
            std::cout << "Ancestor found... " << firstVector[--k]->m_nData << std::endl;
            return 0;
        }
    }
    
    if( firstVector.size() == 1 || secVector.size() == 1 )
    {
        std::cout << "Ancestor found... " << pFive->m_nData << std::endl;
    }
    
    return 0;
}

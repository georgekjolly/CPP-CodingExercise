//
//  main.cpp
//  BTree_Root_to_Node_Path
//
//  Created by George Jolly on 5/31/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class BTree
{
public:
    
    BTree( int nData ) : m_nData( nData),pRight(0),pLeft(0)
    {
        
    }
    
    static bool FindRootToNodePath( BTree* pRoot, BTree* pSearchNode, vector<BTree*>& pPath )
    {
        if( pRoot == 0 || pSearchNode == 0 )
            return false;
        
        pPath.push_back(pRoot);
        
        if( pRoot == pSearchNode )
        {
            return true;
        }
        
        if( FindRootToNodePath(pRoot->pLeft, pSearchNode, pPath )) return true;
        if( FindRootToNodePath(pRoot->pRight,pSearchNode, pPath )) return true;
        
        pPath.pop_back();
           
        return false;
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
    
    int nDepth = BTree::getMaxDepth( pFive );

    std::cout << "Depth = " << nDepth << "\n\n";
    
    std::cout << "BFS\n";
    
    for( int i = 0 ; i < nDepth ; ++i )
    {
        BTree::printNodes( pFive, i );
        std::cout << "\n";
    }

    std::cout << "\n";
    
    vector<BTree*> pPath;
    
    BTree::FindRootToNodePath(pFive, pOne, pPath );
    
    std::cout << "Path\n";
    for( int i = 0 ; i < pPath.size() ; ++i )
    {
        std::cout << pPath[i]->m_nData << "\t";
    }
    
    std::cout << std::endl;
    
    return 0;
}

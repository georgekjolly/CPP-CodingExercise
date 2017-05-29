//
//  main.cpp
//  BSTreeBasicOperations
//
//  Created by George Jolly on 5/26/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class BSTNode
{
public:

    BSTNode( int nData_i ) : pRight(0), pLeft(0), m_nData(nData_i)
    {
        
    }
    
    static BSTNode* createNode( int nData )
    {
        BSTNode* pNewNode = new BSTNode( nData );
        return pNewNode;
    }
    
    static void AddNode( BSTNode* pRootNode, int nData_i )
    {
        BSTNode* pTmpPtr = 0;
        BSTNode* pCurrent = pRootNode;
        
        while( pCurrent )
        {
            pTmpPtr = pCurrent;
            if( nData_i > pCurrent->m_nData )
            {
                pCurrent = pCurrent->pRight;
            }
            else
            {
                pCurrent = pCurrent->pLeft;
            }
        }
        
        if( nData_i > pTmpPtr->m_nData )
        {
            pTmpPtr->pRight = createNode(nData_i);
        }
        else
        {
            pTmpPtr->pLeft = createNode(nData_i);
        }
    }
    
    static void preorder( BSTNode* pRoot_i )
    {
        if( pRoot_i == 0 )
        {
            return;
        }
        std::cout << pRoot_i->m_nData << "\t";
        preorder(pRoot_i->pLeft);
        preorder(pRoot_i->pRight);
    }
    
    
    static void postorder( BSTNode* pRoot_i )
    {
        if( pRoot_i == 0 )
        {
            return;
        }
        postorder(pRoot_i->pLeft);
        postorder(pRoot_i->pRight);
        
        std::cout << pRoot_i->m_nData << "\t";
    }

    
    static void inorder( BSTNode* pRoot_i )
    {
        if( pRoot_i == 0 )
        {
            return;
        }
        inorder(pRoot_i->pLeft);
        std::cout << pRoot_i->m_nData << "\t";
        inorder(pRoot_i->pRight);
        
    }
    
    
    static bool searchNode( BSTNode* pRootNode, int nData_i )
    {
        
        while( pRootNode )
        {
            if( nData_i == pRootNode->m_nData )
            {
                return true;
            }
            
            if( nData_i > pRootNode->m_nData )
            {
                pRootNode = pRootNode->pRight;
            }
            else
            {
                pRootNode = pRootNode->pLeft;
            }
        }
        return false;
    }
    
    
    
    static BSTNode* getMaxNode( BSTNode* pRootNode )
    {
        if( pRootNode == 0 )
        {
            return 0;
        }
        
        if( pRootNode->pRight == 0 )
        {
            return pRootNode;
        }
        
        return getMaxNode( pRootNode->pRight );
    }
    
    
    static BSTNode* getMinNode( BSTNode* pRootNode )
    {
        if( pRootNode == 0 )
        {
            return 0;
        }
        
        if( pRootNode->pLeft == 0 )
        {
            return pRootNode;
        }
        
        return getMaxNode( pRootNode->pLeft );
    }
    
    
    static BSTNode* deleteNode( BSTNode* pRootNode, int nData_i )
    {
        if( pRootNode == 0 )
            return 0;
        
        if( pRootNode->m_nData == nData_i )
        {
            // delete it
            std::cout << "\nFound " << nData_i << std::endl;
            
            if( pRootNode->pLeft == 0 && pRootNode->pRight == 0 )
            {
                delete pRootNode;
                pRootNode = NULL;
            }
            else if( pRootNode->pLeft )
            {
                BSTNode* pMaxNode = getMaxNode( pRootNode->pLeft );
                pRootNode->m_nData = pMaxNode->m_nData;
                pRootNode->pLeft = deleteNode(pRootNode->pLeft, pMaxNode->m_nData );
            }
            else
            {
                BSTNode* pMinNode = getMinNode( pRootNode->pRight );
                pRootNode->m_nData = pMinNode->m_nData;
                pRootNode->pRight = deleteNode(pRootNode->pRight, pMinNode->m_nData );
            }
            
        }
        else if ( nData_i > pRootNode->m_nData )
        {
            pRootNode->pRight = deleteNode(pRootNode->pRight, nData_i);
        }
        else
        {
            pRootNode->pLeft = deleteNode(pRootNode->pLeft, nData_i);
        }
        return pRootNode;
    }
    
    
    static void BFS( BSTNode* pRootNode )
    {
        std::cout << "B  F   S" << std::endl;
        if( pRootNode == 0 )
            return;
        
        queue<BSTNode*> NodeQ;
        NodeQ.push(pRootNode);
        
        while (NodeQ.empty() == false)
        {
            BSTNode* pCurrent = NodeQ.front();
            std::cout << pCurrent->m_nData << "\t";
            NodeQ.pop();
            
            if( pCurrent->pLeft)
            {
                NodeQ.push( pCurrent->pLeft );
            }
            
            if( pCurrent->pRight)
            {
                NodeQ.push( pCurrent->pRight );
            }
        }
        
    }
    
    
  
    
private:
    
    BSTNode* pRight;
    BSTNode* pLeft;
    int m_nData;
};



int main(int argc, const char * argv[]) {

    BSTNode* pRoot = BSTNode::createNode(10);
    
    BSTNode::AddNode( pRoot, 5);
    BSTNode::AddNode( pRoot, 8);
    BSTNode::AddNode( pRoot, 4);
    
    BSTNode::preorder( pRoot );
    std::cout << std::endl;
    BSTNode::postorder( pRoot );
    std::cout << std::endl;
    BSTNode::inorder( pRoot );
    std::cout << std::endl;

    BSTNode::BFS(pRoot);
    
    std::cout << "Search returns " << BSTNode::searchNode( pRoot, 5) << std::endl;
    
    pRoot = BSTNode::deleteNode(pRoot, 10);
    
    BSTNode::inorder( pRoot );
    std::cout << std::endl;
    
    return 0;
}

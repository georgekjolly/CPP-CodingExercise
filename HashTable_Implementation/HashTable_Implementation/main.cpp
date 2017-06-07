//
//  main.cpp
//  HashTable_Implementation
//
//  Created by George Jolly on 6/6/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <list>
#include <functional>

#define TABLSIZE 128

using namespace std;
// Hash table/map implementation using single link list.

template <class K, class V>
class HashNode
{
public:
    
    HashNode( const K& k_i, const V& v_i)
    {
        k = k_i;
        v = v_i;
        pNext = 0;
    }
    
    const K& getKey()
    {
        return k;
    }
    
    const V& getValue()
    {
        return v;
    }
    
    void setKey( const K& k_i )
    {
        k = k_i;
    }
    
    void setValue( const V& v_i )
    {
        v = v_i;
    }
    
    HashNode* pNext;
    
private:
    
    K k;
    V v;
    
};


//template< class hK, class hV >
template <class K, class V>
class HashTable
{
public:
    HashTable()
    {
        for( int i = 0 ; i < TABLSIZE ; ++i )
        {
            m_List[i] = NULL;
        }
    }
    
    
    void put( const K& k , const V& v )
    {
        std::hash<K> objHash;
        size_t hashCode = objHash(k)%TABLSIZE;
    
        HashNode<K, V>* objHashNode = m_List[hashCode];
        if( objHashNode == NULL )
        {
            HashNode<K, V>* objHashNodeNew = new HashNode<K, V>( k, v);
            m_List[hashCode] = objHashNodeNew;
            return;
        }
        else
        {
            HashNode<K, V>* prev = 0;
            bool b = false;
            while( objHashNode )
            {
                if( objHashNode->getKey() == k )
                {
                    //update
                    objHashNode->setValue( v );
                    b = true;
                    return;
                }
                
                prev = objHashNode;
                objHashNode = objHashNode->pNext;
            }
            prev = new HashNode<K, V>( k, v);
        }
        
    }
    
    bool get( const K &k_i, V& v_o )
    {
        std::hash<K> objHash;
        size_t hashCode = objHash(k_i)%TABLSIZE;;
        
        HashNode<K, V>* objHashNode = m_List[hashCode];
        
        if( objHashNode == NULL )
        {
            return false;
        }
        else
        {
            while( objHashNode )
            {
                if( objHashNode->getKey() == k_i )
                {
                    v_o = objHashNode->getValue();
                    return true;
                }
                objHashNode = objHashNode->pNext;
            }
        }
        
        return false;
    }
    
    
    void remove( const K& k )
    {
        std::hash<K> objHash;
        size_t hashCode = objHash( k )%TABLSIZE;
        
        HashNode<K, V>* objHashNode = m_List[hashCode];

        
        if( objHashNode == NULL )
        {
            std::cout << " key is not present \n..";
            return;
        }
        
        // Navigate to the item and delete it.
        HashNode<K, V>* prev = 0;
        while( objHashNode )
        {
            if( objHashNode->getKey() == k )
            {
                // remove here.
                HashNode<K, V>* tmp = objHashNode;
                if( prev == NULL )
                {
                    m_List[hashCode] = objHashNode->pNext;
                    delete tmp;
                }
                else
                {
                    prev->pNext = objHashNode->pNext;
                    delete tmp;
                }
                return;
            }
            prev = objHashNode;
            objHashNode = objHashNode->pNext;
        }
            
    }
    
private:
    HashNode<K,V>* m_List[TABLSIZE];
};



int main(int argc, const char * argv[]) {

    HashTable<string, string> myHashTable;
    
    string strv;
    myHashTable.put("one","George");
    myHashTable.put("two","Sonia");
    myHashTable.put("three","Ryan");
    myHashTable.put("one","George_1");
    myHashTable.remove("three");
    
    myHashTable.get( "one", strv );
    std::cout << strv << std::endl;;
    
    strv = "";
    myHashTable.get( "two", strv );
    std::cout << strv << std::endl;;
    
    strv = "";
    myHashTable.get( "three", strv );
    std::cout << strv << std::endl;;
    
    return 0;
}

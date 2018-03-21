//
//  main.cpp
//  testHashMap
//
//  Created by George Jolly on 3/21/18.
//  Copyright © 2018 George Jolly. All rights reserved.
//

#include <iostream>
#include <list>

# define TABLESIZE 200


using namespace std;

template <class K, class V>
struct HashStruct
{
    K key;
    V value;
};


template <class K, class V >
class HashMap
{
public:
    
    HashMap()
    {
    
    }
    
    bool erase( K key_i )
    {
        std::hash<K> mObj;
        int hashCode = mObj(key_i)%TABLESIZE;
        
        if( m_HasMap[hashCode].empty())
        {
            return false;
        }

        auto it = m_HasMap[hashCode].begin();
        
        while( it != m_HasMap[hashCode].end())
        {
            if( it->key == key_i )
            {
                m_HasMap[hashCode].erase( it );
                return true;
            }
            ++it;
        }
        
        return false;
        
    }
    
    V get( K key_i )
    {
        std::hash<K> mObj;
        int hashCode = mObj(key_i)%TABLESIZE;
        
        if( m_HasMap[hashCode].empty())
        {
            return -1;
        }
        
        auto it = m_HasMap[hashCode].begin();
        
        while( it != m_HasMap[hashCode].end())
        {
            if( it->key == key_i )
            {
                return it->value;
            }
            ++it;
        }
        
        std::cout << "Value for the key = " << key_i << " not found...\n";
        
        return -1;
    }
    
    void put( K key_i, V val_i )
    {
        std::hash<K> mObj;
        int hashCode = mObj(key_i)%TABLESIZE;
        
        bool bFound = false;
        
        if( m_HasMap[hashCode].empty())
        {
            HashStruct<K,V> objHashSt;
            objHashSt.key = key_i;
            objHashSt.value = val_i;
            m_HasMap[hashCode].push_back( objHashSt );
        }
        else
        {
            auto it = m_HasMap[hashCode].begin();
            
            while( it != m_HasMap[hashCode].end())
            {
                if( it->key == key_i )
                {
                    it->value = val_i;
                    bFound = true;
                    break;
                }
                ++it;
            }
            
            if( bFound == false )
            {
                HashStruct<K,V> objHashSt;
                objHashSt.key = key_i;
                objHashSt.value = val_i;
                m_HasMap[hashCode].push_back( objHashSt );
            }
        }
    }
    
private:
    
    list<HashStruct<K,V>> m_HasMap[TABLESIZE];

};



int main(int argc, const char * argv[]) {

    
    HashMap<int,int> hashMap;
    hashMap.put(100,2);
    hashMap.put(1000,3);
    std::cout << "Get 1000 = " <<  hashMap.get(1000) <<  std::endl;
    //hashMap.erase( 100 );
    std::cout << "Erasing 100 " << hashMap.erase(100) << std::endl;
    std::cout << "Erasing 100 " << hashMap.erase(100) << std::endl;
    
    std::cout << "Erasing 1000 " << hashMap.erase(1000) << std::endl;
    std::cout << "Erasing 1000 " << hashMap.erase(1000) << std::endl;

    return 0;
}

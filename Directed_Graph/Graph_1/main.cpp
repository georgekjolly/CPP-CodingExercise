//
//  main.cpp
//  Graph_1
//
//  Created by George Jolly on 5/22/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <list>
#include <set>
#include <queue>

# define WHITE 0
# define GREY 1
# define BLACK 2

using namespace std;

class Family
{
    
public:
    
    Family( const int nId_i, const string& strName_i ):
    m_id(nId_i),
    m_strName(strName_i)
    {
        
    }
    
    void AddMember(  Family& family_i )
    {
        m_FamilyList.push_back( &family_i );
    }
    
    static void DFS( Family& family_i, set<Family*>& FamilySet )
    {
        std::cout << family_i.m_id << ":" << family_i.m_strName << std::endl;
        
        list<Family*>::iterator it = family_i.m_FamilyList.begin();
        
        while( it != family_i.m_FamilyList.end())
        {
            set<Family*>::iterator itset = FamilySet.find( *it );
            if( itset == FamilySet.end())
            {
                // Insert and call DFS
                FamilySet.insert( *it );
                DFS( **it, FamilySet );
                
            }
            ++it;
        }
    }
    
    static void BFS(  Family& family_i, set<Family*>& FamilySet)
    {
        std::queue<Family*> FamilyQueue;
        FamilyQueue.push(&family_i);
        FamilySet.insert( &family_i );
        
        while( FamilyQueue.empty() == false )
        {
            Family* fm = FamilyQueue.front();
            FamilyQueue.pop();
            std::cout << fm->m_id << ":" << fm->m_strName << std::endl;
            
            list<Family*>::iterator it = fm->m_FamilyList.begin();
            
            while ( it != fm->m_FamilyList.end())
            {
                set<Family*>::iterator itset = FamilySet.find( *it );
                if( itset == FamilySet.end())
                {
                    FamilySet.insert(*it);
                    FamilyQueue.push(*it);
                }
                
                ++it;
            }
        }
    }
    
    
    static bool IsCycle( int color[], Family& family_i )
    {
        color[family_i.m_id] = GREY;
        
        list<Family*>::iterator family_it = family_i.m_FamilyList.begin();
        
        while( family_it != family_i.m_FamilyList.end())
        {
            if( color[(*family_it)->m_id] == GREY )
            {
                return true;
            }
            
            if( color[(*family_it)->m_id] == WHITE )
            {
                if( IsCycle( color,  **family_it ))
                {
                    return true;
                }
            }
            ++family_it;
        }
        
        color[family_i.m_id] = BLACK;
        
        return false;
    }
    
    
private:
    list<Family*> m_FamilyList;
    string m_strName;
    int m_id;
};


int main(int argc, const char * argv[]) {
  
    
    Family George( 1, "George" );
    Family Sonia( 2, "Sonia" );
    Family Ryan( 3, "Ryan" );
    Family Xavior( 4, "Xavior" );

    /*
    George.AddMember(Sonia);
    George.AddMember(Ryan);
    
    Sonia.AddMember(George);
    Sonia.AddMember(Ryan);
    
    Ryan.AddMember(Xavior);
    Ryan.AddMember(Sonia);
    Ryan.AddMember(George);
    
    Xavior.AddMember(Ryan);
    */
    
    George.AddMember(Sonia);
    George.AddMember(Ryan);
    
    Sonia.AddMember(Ryan);
    Ryan.AddMember(Xavior);
    Ryan.AddMember(Ryan);
    
    set<Family*> FamilySet;
    /*
    FamilySet.insert(&Xavior);
    Family::DFS( Xavior, FamilySet );
    */
    FamilySet.clear();
    FamilySet.insert(&George);
    Family::BFS( George, FamilySet );
    
    vector<Family*> FamVector;
    FamVector.push_back(&George);
    FamVector.push_back(&Sonia);
    FamVector.push_back(&Ryan);
    FamVector.push_back(&Xavior);
    

    int color[5];
    
    for( int i=1 ; i <= 4 ; ++i )
    {
        color[i] = WHITE;
    }
    
    bool cycle = false;
    
    for( int i=1 ; i <= 4 ; ++i )
    {
        if( color[i] == WHITE )
        {
            if( Family::IsCycle( color, *FamVector[i]))
            {
                std::cout << "Cycle detected...!!!\n";
                cycle = true;
                break;
            }
        }
    }
    
    if( cycle == false )
    {
        std::cout << "No Cycle detected...\n";
    }
    
    return 0;
}

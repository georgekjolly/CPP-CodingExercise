//
//  main.cpp
//  UnDirected_Graph
//
//  Created by George Jolly on 5/25/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <list>
#include <map>
#include <set>

using namespace std;

class Family
{
public:
    
    Family( int nID, const string& strName_i ):m_id(nID),m_strName(strName_i)
    {
        
    }
    
    void AddMemember( Family& family_i )
    {
        FamilyList.push_back(&family_i);
    }
    
    static bool isCycle( Family& family_i, set<Family*>& visted, map<Family*,Family*>& parentMap, Family* parent_i )
    {
        visted.insert(&family_i);
        
        parentMap[&family_i] = parent_i;
        //parentMap.
        
        list<Family*>::iterator itChild = family_i.FamilyList.begin();
        
        while( itChild != family_i.FamilyList.end())
        {
            set<Family*>::iterator itVisted = visted.find(*itChild);
            if( itVisted == visted.end()) // not found
            {
                if( isCycle(**itChild, visted, parentMap, &family_i ))
                    return true;
            }
            
            if( itVisted != visted.end()) // found
            {
                // Check if child node is child of current node
                Family* parent = parentMap[*itChild];
                
                // Not parent
                if( parent != &family_i )
                {
                    // Cycle found
                    return true;
                }
            }
            ++itChild;
        }
        return false;
    }
    

private:
    int m_id;
    string m_strName;
    list<Family*> FamilyList;
};

int main(int argc, const char * argv[]) {
    
    Family George( 1, "George" );
    Family Sonia( 2, "Sonia" );
    Family Ryan( 3, "Ryan");
    Family( 4, "Xaviour");
    
    George.AddMemember(Sonia);
    Sonia.AddMemember(George);
    
    set<Family*> visted;
    map<Family*,Family*> parentMap;
    if( Family::isCycle( George, visted, parentMap, NULL ))
    {
        std::cout << "Cycle found...\n";
    }
    else
    {
        std::cout << "No Cycle found..\n";
    }
    
    
    return 0;
}

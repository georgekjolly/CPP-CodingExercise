//
//  main.cpp
//  Array-StringPermutation
//
//  Created by George Jolly on 6/9/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> mergeString( vector<string> Array, string last)
{
    vector<string>  newArray;
    for( int i = 0 ; i < Array.size(); ++i )
    {
        string str = Array[i];
        
        for( int i = 0 ; i <= str.length(); ++i )
        {
            string strtmp = str;
            strtmp.insert(i, last );
            newArray.push_back(strtmp);
        }
    }
    
    return newArray;
}

vector<string> permutation( string str )
{
    if( str.length() == 1 )
    {
        vector<string> vectorArray;
        vectorArray.push_back(str);
        return vectorArray;
    }
    else
    {
        int nLastIdx = str.length()-1;
        string last = str.substr(nLastIdx);
        string rest = str.substr(0,nLastIdx);
        
        vector<string> res=  mergeString( permutation(rest),last);
        return res;
    }
    
}


int main(int argc, const char * argv[]) {
 
    vector<string> stringVec = permutation("abc");
    
    vector<string>::iterator it = stringVec.begin();
    while (it != stringVec.end()) {
        
        std::cout << *it << std::endl;
        ++it;
    }
    
    return 0;
}

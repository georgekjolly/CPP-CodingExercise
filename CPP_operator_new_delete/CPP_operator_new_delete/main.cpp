//
//  main.cpp
//  CPP_operator_new_delete
//
//  Created by George Jolly on 6/5/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>

class Test
{
public:
    
    static void* operator new( size_t size_i )
    {
        return ::operator new(size_i);
    }
    
    static void* operator new[]( size_t size_i )
    {
        return ::operator new[](size_i);
    }

    Test()
    {
        std::cout << "Test Constructor...\n";
    }
    
    ~Test()
    {
        std::cout << "Test Destructor...\n";
    }
    
    
    static void operator delete( void* ptr_i )
    {
        ::operator delete( ptr_i);
    }

    static void operator delete[]( void* ptr_i )
    {
        ::operator delete[]( ptr_i);
    }
    
    int m_nData;
    
};


int main(int argc, const char * argv[]) {

    
    Test* refPtr = new Test[10]();
    delete [] refPtr;
    
    Test* refPtr1 = new Test();
    delete refPtr1;
    
    return 0;
}

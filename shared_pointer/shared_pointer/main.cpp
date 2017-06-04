//
//  main.cpp
//  shared_pointer
//
//  Created by George Jolly on 6/4/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>

class Abc
{
public:
    
    int m_nAbc;

};

template <class T>
class shared_pointer
{
public:
    
    shared_pointer( T* Ponter_i )
    {
        m_pointer = Ponter_i;
        m_pnCtr = new int;
        *m_pnCtr = 1;
    }
    
    
    T& operator *()
    {
        return *m_pointer;
    }
    
    T* operator->()
    {
        return m_pointer;
    }
    
    
    shared_pointer( const shared_pointer& objRef )
    {
        this->m_pointer = objRef.m_pointer;
        this->m_pnCtr = objRef.m_pnCtr;
        ++(*(this->m_pnCtr));
    }
    
    shared_pointer& operator=( const shared_pointer& objRef )
    {
        --(*(this->m_pnCtr));
        
        update();
        
        this->m_pointer = objRef.m_pointer;
        this->m_pnCtr = objRef.m_pnCtr;
        
        ++(*(this->m_pnCtr));
        
        return *this;
    }
    
    ~shared_pointer()
    {
        --(*(this->m_pnCtr));
        
        update();
    }
    
    void update()
    {
        std::cout << " this->m_pnCtr = " << *(this->m_pnCtr) << std::endl;
        if( *(this->m_pnCtr) <= 0  )
        {
            delete this->m_pnCtr;
            delete this->m_pointer;
            
            this->m_pointer = 0;
            this->m_pnCtr = 0;
        }

    }
    
private:
    
    T* m_pointer;
    int* m_pnCtr;
};

int main(int argc, const char * argv[]) {

    shared_pointer<int> objSP( new int());
    *objSP = 10;
    std::cout << "Val of integer = " << *objSP << std::endl;
    
    shared_pointer<Abc> objAbc( new Abc());
    
    objAbc->m_nAbc = 10;
    
    shared_pointer<Abc> objAbc1( new Abc() );
    
    objAbc1 = objAbc;
    
    return 0;
}

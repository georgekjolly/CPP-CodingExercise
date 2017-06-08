//
//  main.cpp
//  Priority_Queue
//
//  Created by George Jolly on 6/7/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Matrix
{
public:
    
    int nNumber;
    
    int nCol;
    int nRaw;
};

struct MatrixCompare
{
    bool operator()(const Matrix &t1, const Matrix &t2) const
    {
            return t1.nNumber > t2.nNumber;
    }
};



int main(int argc, const char * argv[]) {
    
    
    priority_queue<Matrix, vector<Matrix>, MatrixCompare> MatrixQueue;
    
    Matrix obj1;
    obj1.nNumber = 10;
    
    Matrix obj2;
    obj2.nNumber = 20;
    
    Matrix obj3;
    obj3.nNumber = 5;
    
    MatrixQueue.push(obj1);
    MatrixQueue.push(obj2);
    MatrixQueue.push(obj3);
    
    //while (MatrixQueue.empty() == false )
    {
        Matrix t = MatrixQueue.top();
        std::cout << t.nNumber << std::endl;
        MatrixQueue.pop();
        
    }
    
    Matrix obj4;
    obj4.nNumber = 2;
    MatrixQueue.push(obj4);
    
    std::cout << "---------------------\n";
    
    while (MatrixQueue.empty() == false )
    {
        Matrix t = MatrixQueue.top();
        std::cout << t.nNumber << std::endl;
        MatrixQueue.pop();
    }
    
    return 0;
}

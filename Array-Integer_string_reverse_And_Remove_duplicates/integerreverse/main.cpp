//
//  main.cpp
//  integerreverse
//
//  Created by George Jolly on 6/8/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>


void reverseString( char ch[], int nLastIdx, int nStartIdx )
{
    if( nStartIdx >=  nLastIdx )
    {
        return;
    }
    
    char tmp = ch[nStartIdx];
    ch[nStartIdx] = ch[nLastIdx];
    ch[nLastIdx] = tmp;
    
    
    reverseString(ch, nLastIdx-1, nStartIdx+1);
}


int reverseInteger( int num )
{
    int revnum = 0;
    while( num > 0 )
    {
        revnum = revnum*10 + num%10;
        num = num/10;
    }
    
    return revnum;
}

int compare( const void* ch1, const void* ch2 )
{
    return (*((char*)ch1) - *((char*)ch2));
}

void removeDuplicate( char ch[] )
{
    //sort;
    
    qsort(ch, strlen(ch), sizeof(char), compare );
    
    std::cout << ch << std::endl;
    
    int ip_end = 1;
    int res_end = 1;
    
    while( *(ch + ip_end ))
    {
        if( *(ch+ip_end) != *(ch+ip_end-1))
        {
            *(ch + res_end) = *(ch+ip_end);
            ++res_end;
        }
        
        ++ip_end;
    }
    
    *(ch + res_end) = '\0';
}

int main(int argc, const char * argv[]) {
 
    
    std::cout << "Reverse Integer = " << reverseInteger( 123 ) << std::endl;
    
    
    char ch[] = "george";
    reverseString( ch, strlen(ch) - 1,0);
    
    std::cout << "Reverse string = " << ch << std::endl;
    
    // remove duplicates.
    char chstr[] = "abddcc";
    
    removeDuplicate( chstr);
    
    std::cout << chstr << std::endl;
    
    
    
    return 0;
}

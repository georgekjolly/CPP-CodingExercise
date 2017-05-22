//
//  main.cpp
//  MovieProblemReal
//
//  Created by George Jolly on 3/20/17.
//  Copyright © 2017 George Jolly. All rights reserved.
//

#include <iostream>
#include <list>
#include <set>

using namespace std;

class Movie
{
    
public:
    
    Movie( int id_i, float rate_i )
    {
        id = id_i;
        rate  = rate_i;
    }
    
    bool operator < ( const Movie& movie ) const
    {
        return ( movie.rate < rate );
    }
    
    void AddMovies( Movie& mvi_i )
    {
        movieList.push_back(mvi_i);
    }
    
    list<Movie> getList()
    {
        return movieList;
    }
    
    static list<Movie> getRecommendations( Movie& mvie, int N )
    {
        list<Movie> result;
        set<Movie> visited;
        BFS( mvie, visited);
        
        set<Movie>::iterator it = visited.begin();
        
        while( it != visited.end())
        {
            std::cout << it->id << "  " << it->rate << std::endl;
            ++it;
        }
        
        return result;
    }
    
    static void BFS( Movie& mvie, set<Movie>& result)
    {
        list<Movie> objList = mvie.getList();
        
        list<Movie>::iterator it = objList.begin();
        
        while( it != objList.end())
        {
            set<Movie>::iterator itmv = result.find(*it);
            if( itmv == result.end())
            {
                result.insert( *it );
                BFS(*it, result );
            }
            ++it;
        }
        
    }
    
private:

    list<Movie> movieList;
    int id;
    float rate;
};




int main(int argc, const char * argv[]) {
 
    
    Movie objMovie1_2( 1, 1.2 );
    Movie objMovie2_4( 2, 2.4 );
    Movie objMovie3_6( 3, 3.6 );
    Movie objMovie4_8( 4, 4.8 );
    
    objMovie1_2.AddMovies( objMovie2_4 );
    objMovie1_2.AddMovies( objMovie3_6 );
    
    objMovie2_4.AddMovies(objMovie1_2);
    objMovie2_4.AddMovies(objMovie4_8);
    
    objMovie3_6.AddMovies(objMovie1_2);
    objMovie3_6.AddMovies(objMovie4_8);
    
    objMovie4_8.AddMovies(objMovie2_4);
    objMovie4_8.AddMovies(objMovie3_6);
    
    Movie::getRecommendations( objMovie4_8, 2 );
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

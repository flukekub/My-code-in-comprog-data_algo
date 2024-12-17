#include<bits/stdc++.h>
using namespace std ;
int a[1000][1000] ;

int r, c , t ;

set<pair<int,int>> mem( ){
    set<pair<int,int>> s ;
    for( int i = 0 ; i < r  ;i++  ){
        for( int j = 0 ; j < c ; j++ ){
            if( a[i][j] == 1 ){
                s.insert( make_pair( i ,  j));
            }
        }
    }
    return s ;
}



int main(){
   
    cin >> r  >> c >> t ;
    
    for( int i = 0 ; i < r ; i++ ){
        for( int j = 0 ; j < c ; j++){
            int x ;
            cin >> x ;
            a[i][j] = x ;
        }
    }
    for( int i = 0 ; i < t ; i++ ){
        for( auto e : mem() ){
            if( a[e.first+1][e.second] == 0 )a[e.first+1][e.second] = 1 ; 
            if( a[e.first-1][e.second] == 0 && e.first >= 0  )a[e.first-1][e.second] = 1 ;
            if( a[e.first][e.second+1] == 0 )a[e.first][e.second+1] = 1 ;
            if( a[e.first][e.second-1] == 0 && e.second >= 0 )a[e.first][e.second-1] = 1 ;
            
        }
    }
    int count = 0 ;
    for( int i = 0 ; i < r ; i++ ){
        for( int j = 0 ; j < c ; j++){
           if(  a[i][j]  == 1 ){
            count++;
           } 
        }
    }
    cout << count ;
}
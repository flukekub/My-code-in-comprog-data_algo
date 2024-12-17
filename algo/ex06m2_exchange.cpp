#include<bits/stdc++.h>
using namespace std;
double dist[500][500];

bool solve(int n ){
    for( int k = 0 ;  k < n ; k ++){
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n ; j++){
                dist[i][j] = max( dist[i][j], dist[i][k] * dist[k][j]);
            }
        }
    }
    bool tick = false ;
    for( int i = 0 ; i < n ; i++ ){
        if( dist[i][i] > 1 )
            tick = true ;
    }
    return tick ;
}


int main(){
    int n ;
    cin >> n ;
    while( n-- ){
        int m ;
        cin >> m ;
        
        for( int i =0 ; i < m ; i++){
            for( int j = 0 ; j < m ; j++){
                cin >> dist[i][j];
            }
        }
        if(solve(m)){
            cout << "YES" <<"\n";
        }else{
            cout << "NO"<<"\n";
        }


    }
}
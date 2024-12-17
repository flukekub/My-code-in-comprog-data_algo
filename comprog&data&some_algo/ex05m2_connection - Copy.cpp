#include<bits/stdc++.h>
using namespace std ;

void bfs( int a , vector< list<int>> & v ,int cc_num , int k, vector<int> & visit ){
    visit[a] = cc_num ;
    if( k  > 0 )for( auto e : v[a]){
        bfs(e,v,cc_num,k-1,visit );
    }
}



int main( ){
    int  n , m , k ;
    cin >> n >> m  >> k ;
    vector< list<int>> v(n) ;
    for( int i =0 ; i < m ; i++){
        int  x , y ;
        cin >> x >> y ;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    int max = 0 ;
    for( int i = 0 ; i < n ; i++ ){
        int cc_num =1 ;
        vector<int> visit (n,-1);
        bfs( i , v , cc_num,k,visit);
        int count = 0 ;
        
        for( int j = 0 ; j < n ;j++){
            if( visit[j] == 1 )count++;
        }
        
        if( count > max )max = count ;
    }
    cout << max ;
}
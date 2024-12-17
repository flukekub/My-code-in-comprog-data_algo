#include<bits/stdc++.h>
using namespace std ;
int n ; 
vector<int> v[100000];
int distanc[100000];
int ans ;

void dfs( int a , int d , int parent){
    distanc[a] = d ;
    for( auto e : v[a]){
        if( distanc[e] == 0 ){
            
            dfs( e, d+1 , a ) ;
        }else if( e != parent){
            ans = abs( d - distanc[e])+1 ;
        }
        
        
    }
    
}


int main(){
    
    cin >> n ;
    for( int i = 0; i < n ; i++ ){
        int x , y ;
        cin >> x >> y ;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs( 0 , 1 , -1);
    cout << "\n" << ans ;
}

#include<bits/stdc++.h>
using namespace std ;
int n ; 
vector<int> v[10];
int distanc[10];
int ans ;

void dfs( int a , int d , int parent){
    distanc[a] = d ;
    cout<< " --> " << a ;
    for( auto e : v[a]){
        if( distanc[e] == 0 ){
            dfs( e, d+1 , a ) ;
        }else if( e != parent){
            //cout << "\nAt " << a << " d is  " << d << " e is  "<< distanc[e]  <<"\n";
            ans = abs( d - distanc[e])+1 ;
            //cout << "\n" << ans << "\n";
            cout << "\n answer ! \n";
        }      
    }
    cout << " -->* " << parent  ;
}


int main(){
    cin >> n ;
    for( int i = 0; i < n ; i++ ){
        int x , y ;
        cin >> x >> y ;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs( 5 , 1 , -1);
    cout << "\n" << ans ;
}

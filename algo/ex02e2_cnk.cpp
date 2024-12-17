#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n , k ;
    cin >> n >> k ;
    map<pair<int,int>, int > m ;
    m[{0,0}] = 1 ; 
    m[{1,0}] = 1 ;
    m[{1,1}] = 1 ;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 0 ; j <= k ; j++ ){
            if( j == 0  || i == j ){
                m[{i,j} ] = 1 ;
            }
            m[{i,j}] = m[{i-1,j-1}] + m[{i-1,j}];
        }
    }
    cout << m[{n,k}] ; 
}
#include<bits/stdc++.h>
using namespace std ;
int a_k_mod_m( int  a , int  k , int  m ){
    if( k == 0 ){
        return 1 ;
    }else if( k % 2 == 0 ){
        return (a_k_mod_m( a , k/2 , m) * a_k_mod_m( a , k/2 , m)) % m ;
    }else if( k % 2 == 1 ){
        return (a*(a_k_mod_m( a , k/2 , m) * a_k_mod_m( a , k/2 , m) )) % m ;
    }
}

int main(){
    int a , k , m ;
    cin >> a >> k >> m ;
   cout <<  a_k_mod_m( a, k , m );
}
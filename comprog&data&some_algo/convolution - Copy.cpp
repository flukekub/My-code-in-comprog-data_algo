#include<bits/stdc++.h>
using namespace std ;
int main(){
    long long int nx , nh , a , b ;
    cin >> nx >> nh >> a >> b ;
    map< long long int,long long int> x ,h ;
    while( nx-- ){
        int c , d ;
        cin >> c >>  d ;
        x[c] = d ;
      
    }

    while( nh-- ){
        long long int c , d ;
        cin >> c >>  d ;
        h[c] = d ;
       
    }

    for ( int rob = a ; rob <= b ; rob++){
        long total = 0 ;
        for( long long int  k = -6969 ; k <= 6969 ; k++ ){
            //cout << x[k] << " "  << h[k-rob] ; 
            total += x[k]*h[rob - k] ;
        }
        cout << total << " ";
    }
    
}
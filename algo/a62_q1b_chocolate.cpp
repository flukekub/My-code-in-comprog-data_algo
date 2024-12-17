#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n , k ;
    cin >> n >> k ;
    set<int> s ;
    for( int i= 0 ; i <  k ;i++){
        int x ;
        cin >> x ;
        s.insert( x );
    }
    int arr[n+1] ;
    arr[0] = 1;
    for( int i = 1 ; i <= n ; i++ ){
        long long sum = 0 ;
        for( auto e : s ){
            if( e <= i ){
                sum = (sum + arr[i - e])%1000003 ; 
            }
        }
        arr[i] = sum ;
    }
    cout << arr[n] ;
}
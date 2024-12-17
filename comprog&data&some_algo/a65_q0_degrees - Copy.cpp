#include<bits/stdc++.h>
using namespace std ;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n ;
    cin >> n ;
    int arr[n][n];
    for( int i = 0 ; i< n ;i++){
        for( int j = 0 ; j < n ;j++){
            int x ;
            cin >> x ;
            arr[i][j] = x ;
        }
    }
    int max = 0 ;
    map<int,int> m ;
    for( int i = 0 ; i  < n ;i++ ){
        int count = 0 ;
        for( int j = 0 ; j< n ;j++){
            if( arr[i][j] == 1 )count++;
        }
        m[count] += 1 ;        
        if( count > max )max = count ;
    }

    for( int i = 0 ; i < max+1 ;i++ ){
        cout << m[i] << " " ;
    }
}
#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n ,m;
    cin >> n >> m ;
    vector<int> v ;
    for( int i = 0  ; i < n  ; i++ ){
        int x ;
        cin >> x ;
        v.push_back( x );
    }
    while( m-- ){
        int y ;
        cin>> y ;
        if( y < *v.begin() ){
            cout << -1 << "\n";
            continue ;
        }else{
            cout << upper_bound(v.begin(),v.end(),y) - v.begin() - 1 << "\n";
        }

    }
}
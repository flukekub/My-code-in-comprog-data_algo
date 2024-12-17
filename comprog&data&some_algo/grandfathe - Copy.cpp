#include<bits/stdc++.h>
using namespace std ;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    long long int n , m ;
    cin >> n >> m ;
    map<long long int, long long int > sampan ;
    while( n-- ){
        long long int x , y ;
        cin >> x >> y ;
        sampan[y] = x ;
    }
    while( m-- ){
        long long int  f , s ;
        cin >> f >> s ;
        if( sampan[sampan[f]] == sampan[sampan[s]]  && sampan[sampan[f]] != 0 && sampan[sampan[s]] != 0 && f != s ){
            cout << "YES" << "\n" ;
        }else{
            cout << "NO" << "\n" ;
        }
    }

}
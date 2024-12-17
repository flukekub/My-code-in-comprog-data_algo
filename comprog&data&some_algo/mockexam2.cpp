#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n ,k;
    cin >> n >> k ;
    map<string,set<int>> m ;
    while( n-- ){
        string ID ;
        int send_total ;
        cin >> ID >> send_total ;

        m[ID].insert( send_total );
        
    }
    int count = 0 ;
    for( auto e : m ){
        if( (e.second).size() == k ){
            count++;
        }
    }
    cout << count ;
}
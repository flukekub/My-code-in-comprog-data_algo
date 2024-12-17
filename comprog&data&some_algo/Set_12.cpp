#include<bits/stdc++.h>
using namespace std ;
int main(){
    set<int> s ;
    int n ,k= 1;
    bool found = false;
    while( cin >> n ){
        if( s.find(n) == s.end()){
            s.insert(n);
        }else{
            found = true ;
            break;
        }
            
        k++;
    }
    if( found ){
        cout << k ;
    }else {
        cout << -1 ;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    long long int n ;
    cin >> n ;
    set<long long int> ss ;
    bool repeat = false ;
    while( n-- ){
        long long int x ;
        cin >> x ;
        if( ss.find(x) != ss.end() ){
            repeat = true ;
        }
        ss.insert(x); 
    }
    bool onto = true ;
    for( auto i = ss.begin() , end = --ss.end(); i != end ; i++ ){
        if( ss.find(*i +1) == ss.end()){
            onto = false ;
            break;
        }
    }
    if( !repeat && onto ){
        cout << "YES";
    }else{
        cout << "NO" ;
    }
    
}
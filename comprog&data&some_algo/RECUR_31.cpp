#include<bits/stdc++.h>
using namespace std ;

set< string > anagram( string s ){
    set <string > ana ;
    sort( s.begin() , s.end() );

    do{
        ana.insert(s) ;
    }while( next_permutation( s.begin() , s.end() ) );
    return ana ;
}


int main(){
    string s ;
    cin >> s ;
    for( auto e :  anagram(s) ){
        cout << e << " " ;
    }
}
#include<bits/stdc++.h>
using namespace std ;
int main(){
    string station1 , station2 ;
    string s ;
    string here ;
    map<string,set<string>> pai ,klub;
    while( getline( cin , s )  ){
        if( s.find(' ') == -1 ){
            here = s ;
            break;
        }
        int i  = s.find( ' ') ;
        station1 = s.substr(0,i);
        station2 = s.substr( i+1 );

        pai[station1].insert(station2);
        klub[station2].insert(station1);
        
    }
    set< string > answer ;
    for( string e : pai[here]){
        answer.insert(e);
        for( auto c : pai[e]){
            answer.insert(c);
        }
        for( auto d : klub[e]){
            answer.insert(d);
        }
    }
    for( string e : klub[here]){
        answer.insert(e);
        for( auto d: pai[e]){
            answer.insert(d);
        }
        for( auto c : klub[e]){
            answer.insert(c);
        }
    }
    for( auto e : answer ){
        cout << e << "\n";
    }
    if( answer.empty()){
        cout << here ;
    }
}
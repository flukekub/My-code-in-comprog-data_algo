#include<bits/stdc++.h>
using namespace std ;
int main(){
    set<string> winner ;
    set<string> loser ;
    string win ,lose ;
    while( cin >> win >> lose){
        winner.insert(win);
        loser.insert(lose);
    }
    bool have = false ;
    for(auto e : winner){
        if( loser.find(e) == loser.end() ){
            have = true ;
            cout << e << " ";
        }
    }
    if( !have){
        cout << "None";
    }
}
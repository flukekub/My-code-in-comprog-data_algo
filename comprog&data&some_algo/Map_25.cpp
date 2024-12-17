#include<bits/stdc++.h>
using namespace std ;

bool intersec( set<string> s1 ,set<string> s2 ){
    for( auto e : s1){
        if( s2.find( e ) != s2.end()){
            return true ;
        }
    }
    return false ;
}

int main(){
    int n ; 
    cin >> n ;
    vector <  pair<string , set<string>> > v ;
    map < string , set<string>> m ;
    while( n-- ){
        string ID ,address ;
        cin >> ID ;
        set<string > sett ;
        while( cin >> address ){
            if ( address == "*"){
                break;
            }   
            sett.insert( address );
        }
        m[ID] = sett ;
        v.push_back(make_pair(ID,sett)) ;
    }
    string key_id ;
    cin >> key_id ;
    bool tick = true ;
    for( auto e : v ){
        if( e.first == key_id ){
            continue ;
        }

        if ( intersec( e.second , m[key_id]) ){
            tick = false ;
            cout << ">> " << e.first << "\n" ;
        }

    }

    if( tick ){
        cout << ">> Not Found";
    }
    
}
#include<bits/stdc++.h>
using namespace std ;
int main(){
    string song_name , singer ,type_song , time ;
    int time_sec = 0  ;
    vector< pair<int,string>> v ;
    set<string> tpe_s ;
    while( cin >> song_name >> singer >> type_song >> time ){
        tpe_s.insert(type_song);
        int i = 0 ;
        string minute = "",second = "" ;
        while( time[i] != ':' ){
            minute += time[i];
            i++;
        }
        second = time.substr( i+1);
        time_sec = stoi(minute) * 60 +  stoi(second) ;
        
        
       bool tick = true ;     
       for( auto & e : v){
            if( e.second == type_song){
                e.first = e.first - time_sec ;
                tick = false ;
            }
       }
       if(tick)
            v.push_back(make_pair(-time_sec ,type_song));
        

    }
    sort(v.begin(),v.end());
    int end = 3 ;
    if( tpe_s .size() < end ){
        end = tpe_s.size() ;
    }


    for( int i =0 ; i < end ; i++){
        cout << v[i] .second << " --> " << -v[i].first/60 << ":" << -v[i].first % 60 << "\n";
    }
    
}
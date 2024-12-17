#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n ;
    cin >> n ; 
    map<string , vector<pair<string,int>> > item ;
    set<string> khon ;
    
    while( n-- ){
        string action , name , sinka ;
        int raka ; 
        cin >> action  ;
        if( action == "B"){
            
            cin >> name >> sinka >> raka ;
            khon.insert( name );

            item[sinka].push_back( make_pair( name , raka ) );
        }else if (  action == "W"){
            cin >> name >> sinka ;

            for( auto & e : item ){
                if( e.first == sinka ){
                    for( auto & c : e.second ){
                        if( c.first == name ){
                           c.second = 0 ;

                        }
                    }
                }
            }
        }
    }
    map <string,int> max_raka_sinka ;
    for( auto e : item ){
        int max = -6969 ;
        for( auto c : item[e.first]){
            if( c.second > max ){
                max = c.second;
            }
        }
        max_raka_sinka[e.first] =  max ;
    }
    map<string,pair<int,set<string>>> answer ;
   for( auto e : item  ){
        string s ;
        int x ;
        for( auto c : item[e.first] ){
            
            if( max_raka_sinka [e.first] ==  c.second ){
                s = c.first ;
                x = c.second ;
                (answer[c.first]).first += x ; 
                ((answer[c.first]).second).insert( e.first ) ; 
                break;
            } 
           
        }
       
    } 
    for( auto e : khon ){
        cout << e << ": ";
        if( answer.find( e ) == answer.end() ){
            cout << "$0" << "\n";
        }else{
            if ( answer[e].first == 0 ){
                cout << "$0" << "\n";
                continue ;
            }
            cout << "$" << answer[e].first << " -> " ;
            for( auto c : answer[e].second ){
                cout << c << " " ;
            }
            cout << "\n";
        }
    }
}

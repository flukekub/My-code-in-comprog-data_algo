#include<bits/stdc++.h>
using namespace std;
int main(){
    string name;
    string hergrade;
    pair<string,string> p ;
    vector<pair<string,string>>  v ;
    while ( cin >>  name ){
        if( name == "q"){
            break;
        }
        cin >> hergrade;
        p = { name , hergrade} ;
        v.push_back(p);
    }

    string up ;
    while ( cin >> up ){
        for( int i = 0 ; i < v.size(); i++){
            if( v[i].first == up ){
                if(v[i].second == "D"){
                    v[i].second = "D+";
                }else if(v[i].second == "D+"){
                    v[i].second = "C";
                }else if(v[i].second == "C"){
                    v[i].second = "C+";
                }else if(v[i].second == "C+"){
                    v[i].second = "B";
                }else if(v[i].second == "B"){
                    v[i].second = "B+";
                }else if(v[i].second == "B+"){
                    v[i].second = "A";
                }else if(v[i].second == "F"){
                    v[i].second = "D";
                }
            }
        }
    }


    for( auto e : v ){
        cout << e.first << " " << e.second << "\n";
    }
}
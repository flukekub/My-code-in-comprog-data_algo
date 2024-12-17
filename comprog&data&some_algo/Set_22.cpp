#include<bits/stdc++.h>
using namespace std ;

set<int> union_set ( vector<set<int>> & v ){
    set<int> U ;
    for( set<int> e : v ){
        for( int n : e ){
            U.insert(n);
        }
    }
    return U ;
}
set<int> intersect_set ( vector<set<int>> & v ){
    set<int> U ;
    for( int n : v[0] ){
        bool found = true ;
        for(int i = 1 ; i < v.size() ; i++ ){
            if( v[i].find(n) == v[i].end()){
                found = false ;
            }
        }
        if( found ){
            U.insert(n);
        }
    }
    return U ;
}
set<int> diff_set ( vector<set<int>> & v ){
    set<int> U  = v[0];
    for( int i = 1 ; i < v.size() ; i++ ){
        for( auto n : v[i] ){
            if( U.find(n) != U.end() ){
                U.erase(n);
            }
        }
    }
    
    return U ;
}


int main(){
    vector<set<int>> v ;
     
    string num ;
    while( getline(cin , num)){
        set<int> s ;
        for( int i = 0 ; i < num.length() ; i++ ){
            string ss = "";
            while( num[i] != ' ' ){
                ss += num[i];
                i++;
            }
            s.insert(stoi(ss));
        }
        v.push_back( s );
    }
    
    cout << "U: ";
    if( union_set(v).empty() ){
        cout << "empty set";
    }else{
        for( auto e : union_set(v) ){
            cout << e <<" ";
        }
    }
    cout << "\n";
    //************************************************************** */
    cout << "I: ";
    if( intersect_set(v).empty() ){
        cout << "empty set";
    }else{
        for( auto e : intersect_set(v) ){
            cout << e <<" ";
        }
    }
    cout << "\n";
    //************************************************************** */
    cout << "D: ";
    if( diff_set(v).empty() ){
        cout << "empty set";
    }else{
        for( auto e : diff_set(v) ){
            cout << e <<" ";
        }
    }
    cout << "\n";

}

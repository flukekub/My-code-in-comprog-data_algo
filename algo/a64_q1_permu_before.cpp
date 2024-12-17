#include<bits/stdc++.h>
using namespace std ;

bool checkcondition(vector<int> v ,set<pair<int,int>> s ){
    for( auto e : s ){
        for( int i = 0 ; i < v.size() ; i++ ){
            if( v[i] == e.first ){
                for( int j = i-1 ; j >= 0 ; j-- ){
                    if( e.second == v[j])return false ;
                }
            }
            
        }
    }
    return true ;
}



int main(){
    int n , k;
    cin >> n >> k  ;
    vector<int> v ;
    for( int i = 0 ; i < n ; i++ ){
        v.push_back(i);
    }
    set<pair<int,int>> con ;
    for( int i = 0 ; i < k ; i++ ){
        int x , y ;
        cin >> x >> y ;
        con.insert(make_pair(x,y));
    }
    




    do{
        if( checkcondition( v , con)){
            for( auto e : v ){
                cout << e << " " ;
            }
            cout << "\n" ;
        }
        
    }while( next_permutation(v.begin(),v.end()) );
}
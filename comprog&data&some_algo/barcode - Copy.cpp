#include<bits/stdc++.h>
using namespace std ;
int main(){
    int b , n ;
    cin >> b >> n ;
    vector<int> v ;
   
        for( int i = 0 ; i < n-b ; i++ ){
            v.push_back( 0 ) ;
        }
        for( int i = 0  ; i < b ; i++){
            v.push_back( 1 );
        }
    
    vector< vector<int> > answer ;
    answer.push_back(v);
    while( next_permutation( v.begin(),v.end())){
        vector<int> tmp ;
        for( auto e : v) {
            tmp.push_back(e);
        }
        answer.push_back(tmp);
    }

    for( auto e : answer){
        for( auto c : e ){
            cout << c ;
        }
        cout << "\n";
    }
}
#include<bits/stdc++.h>
using namespace std ;
int n ;
vector<int> v[10001];
int colour[10001];

void colouring( int a , int cc_num  ){
    colour[a] = cc_num;
    for( auto  adj: v[a]){
        if( colour[adj] == 0 ){
            colouring( adj,cc_num);
        }
    }

}
void solve( int cc ){
    for( int i = 1 ; i<= n ;i++ ){
        if( colour[i] == 0 ){
            colouring( i , cc );
            cc++ ;
        }        
    }
}
int main(){
    int   e ;
    cin >> n >> e ;
    for( int i = 0 ; i< e ; i++ ){
        int x ,y ;
        cin >> x >> y ;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    solve( 1 );
    set<int> s ;
    for( int i = 1 ; i<= n ;i++ ){
        s.insert(colour[i]);
    }
    cout << s.size();
}
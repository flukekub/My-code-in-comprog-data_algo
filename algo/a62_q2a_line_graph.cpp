#include<bits/stdc++.h>
using namespace std ;
vector<int> v[100000];
int n ;
map<int,int> m ;
void colouring(int a , int c  ,vector<int> & colour,int parent ){
    colour[a] = c ;
    if( v[a].size() > 2 ){
        m[c] = 1 ;
    }
    for( auto e : v[a]){
        if( colour[e] == 0 ){
            colouring( e , c,colour , a );
        }else if ( e != parent ){
            m[c] = 1 ;
        }
    }

}

vector<int> sol(int cc_num ){
    vector<int> colour(n,0) ;
    for( int i = 0 ; i< n ;i++){
        if( colour[i] == 0 ){
            colouring( i , cc_num, colour,-1);
            cc_num++;
        }
    }
    return colour ;
}

int main(){
    int  e ;
    cin >> n >> e ;
    for( int i = 0 ; i < e ;i++ ){
        int x ,y ;
        cin >> x >> y ;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> cc = sol(1);
    int count = 0 ;

    set<int> s ;
    for( auto e : cc  ){
        s.insert(e);
    }
    for( auto e : s){
        if( m[e] == 0 ){
            count++ ;
        }
    }
    cout << count << "\n";
}
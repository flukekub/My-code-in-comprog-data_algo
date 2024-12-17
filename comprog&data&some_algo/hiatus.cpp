#include<bits/stdc++.h>
using namespace std ;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    
    set<pair<int,int>> v ;
    int n , m ;
    cin >> n >> m ; 
    while( n-- ){
        int x ,y ;
        cin >> x >> y ;
        v.insert(make_pair(x,y));
    }
    
    while( m-- ){
        int x, y ;
        cin >> x>> y ;
       pair<int,int> p = make_pair(x,y);
        if(  p < *v.begin() ){
            cout << "-1 -1 " ;
            continue;
        }else if( v.find(p) != v.end() ){
            cout << "0 0 " ;
        }else{
            pair<int,int> out = *( --v.lower_bound(p)) ;
            cout << out.first <<  " " << out.second << " " ;
        }
    }
}
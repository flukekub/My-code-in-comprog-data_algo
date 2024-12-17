#include<bits/stdc++.h>
using namespace std ;

vector<int> g[10000];
int weight[10000];
vector<int> dist( 10000 ,1e9);

priority_queue< pair<int,int> ,vector<pair<int,int>> , greater<>> pq;
set<int> st ;
void solve(  vector<int> & visit ){
    
    while( !pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int current_weight = p.first ;
        int current_node = p.second ;
        visit[current_node] = 1 ;
        for( auto e : g[current_node]){
            if( current_weight + weight[e] < dist[e] && visit[e] == 0 ){
                dist[e] = current_weight + weight[e] ;
                pq.push( make_pair( dist[e] , e ));
            }
        }
    }
}
int main(){
    int n , m ,k ;
    cin >> n >>  m >> k ;
    

    for( int i = 0; i < k ; i++){
        int x ;
        cin >> x ;
        st.insert(x);
    }
    
    for( int i = 0 ; i < n ; i++){
        
        cin >> weight[i] ;
    }
    for( int i = 0 ; i < m ; i++){
        int u , v ;
        cin >> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }
   for( auto e : st ){
        dist[e] = weight[e];
        pq.push( make_pair( weight[e] , e));
   }
    vector<int> visit(10000,0);
    solve(  visit );
    int max = dist[0];
    for( int i = 0 ; i < n  ; i++ ){
        if( dist[i] > max ){
            max = dist[i];
        }
    }
    cout << max ;
}
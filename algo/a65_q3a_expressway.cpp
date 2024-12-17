#include<bits/stdc++.h>
using std::vector;
using std::cin;
using std::pair;
using std::make_pair;
using std:: priority_queue ;
typedef long long ll ;
vector<pair<ll,ll>> g[800];

priority_queue<pair<ll,ll>,vector<pair<ll,ll>> ,std::greater<>> pq; 

void solve( int start, vector<int> & visit ,vector<ll> & dist){
    visit[start] = 1 ;
    dist[start] = 0 ;
    pq.push( make_pair( dist[start],start));
    while( !pq.empty()){
        pair<int,int> p  = pq.top();
        pq.pop();
        int current_node = p.second;
        int current_weight = p.first;
        visit[current_node] = 1;
        for( auto e : g[current_node]){
            int to_node = e.first ;
            int to_weight = e.second;
            if( to_weight + current_weight < dist[to_node] && visit[to_node] == 0 ){
                dist[to_node] = to_weight + current_weight ;
                pq.push(make_pair(dist[to_node],to_node));
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n ; cin >> n ;
    int w12;cin >> w12;
    g[1].push_back(make_pair(2,w12));
    g[2].push_back(make_pair(1,w12));
    int rob = n-2 ;
    for( int rob = 3 ; rob <= n ; rob++ ){
        int k ;cin >> k ;
        for( int i = 0 ; i < k ; i++){
            int v , w ;
            cin >> v >> w ;
            g[rob].push_back(make_pair( v, w));
            g[v].push_back(make_pair( rob, w));
        }
        vector<int> visit(800,0);
        vector<ll> dist(800,1e9);
        solve( 1 , visit ,dist) ;
        std::cout << dist[2] << " ";
    }
        
    
}
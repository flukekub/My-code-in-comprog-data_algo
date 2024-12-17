#include<bits/stdc++.h>
using namespace std ;
vector<pair<int,int>> g[10000];
vector<int> dist(10000,1e9);
priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<> >pq;
void solve( int start , vector<int> &visit){
    dist[start] = 0 ;
    pq.push( make_pair(dist[start],start ));
    visit[start] = 1 ;
    while( !pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int current_node = p.second;
        int current_weight = p.first;
        visit[current_node] = 1 ;
        for( auto e : g[current_node]){
            int to_node = e.first ;
            int to_weight = e.second;
            if( current_weight + to_weight < dist[to_node] && visit[to_node] == 0 ){
                dist[to_node] = current_weight + to_weight ;
                pq.push(make_pair(dist[to_node],to_node));
            }
        }
    }
}
int main(){
    int n,m,s,t;
    cin >> n >> m >> s >> t ;
    while( m-- ){
        int u , v , w ;
        cin >> u >> v >> w ;
        g[u].push_back(make_pair( v,w));
        g[v].push_back(make_pair(u,w));
    }
    vector<int> visit(10000,0);
    solve(s,visit);
    cout << dist[t];
}
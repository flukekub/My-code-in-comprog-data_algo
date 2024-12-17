#include<bits/stdc++.h>
using namespace std ;
int ci[2000] ;
int co[2000];
vector<int> g[2000];
vector<int> dist(2000,6969696) ;

priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<>>pq;
void solve(int start ,vector<int> &visit ){
    dist[start] = 0 ;
    visit[start] = 1 ;
    pq.push( make_pair( dist[start],start));
    while( !pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int current_node = p.second;
        int current_weight = p.first;
        visit[current_node] = 1 ;
        for( auto e : g[current_node]){
            int to_node = e ;
            int to_weight = ci[e] + co[current_node];
            if( to_weight + current_weight < dist[to_node] && visit[e] == 0 ){
                dist[to_node] = to_weight + current_weight ;
                pq.push(make_pair(dist[to_node],to_node) );
            }
        }
    }


}

int main(){
    int n , edge;
    cin >> n >> edge ;
    for( int i = 0 ; i < n ; i++ ){
        cin >> ci[i] ;
    }
    for( int i = 0 ; i < n ;i++){
        cin >> co[i];
    }
    for( int i = 0 ; i < edge ; i++ ){
        int u , v ;
        cin >> u >> v ; 
        g[u].push_back(v);
    }
    vector<int> visit(2000,0);
    solve(0,visit);
    for( int i = 0 ; i < n  ;i++){
        if( dist[i] == 6969696){
            cout <<  -1 << " ";
        }else{
            cout << dist[i] << " ";
        }
    }
}
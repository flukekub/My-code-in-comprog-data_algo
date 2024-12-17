#include<bits/stdc++.h>
using namespace std ;
vector<pair<int,int>> g[1000];
vector<int> dist(1000,69696969);
priority_queue<pair<int,int> , vector<pair<int,int>>,greater<> > pq ;

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
    int n ;
    cin >> n ;
    for( int i = 0 ;  i < n  ;i++){
        for( int j = 0 ; j< n ; j++){
            int w ;
            cin>>w;
            if( w != -1 && i != j ){
                g[i].push_back( make_pair( j,w));
            }
        }
    }
    vector<int> visit( 1000,0);
    solve( 0 , visit);
    int max = 0 ;
    for( int i = 0 ; i < n ; i++){
        if( dist[i] > max ){
            max = dist[i];
        }
    }
    if( max == 69696969 )
        cout << -1 ;
    else
        cout << max ;
}
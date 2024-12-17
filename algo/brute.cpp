#include<bits/stdc++.h>
using std::vector;
using std::pair;
using std::make_pair;
using std::cin ;
using std::cout ;
using std::priority_queue;
vector<pair<int,int>> g[600];

priority_queue< pair<int,int>,vector<pair<int,int> >,std::greater<> > pq;
void solve( int start , vector<int> &dist , vector<int>& visit ){
    visit[start] = 1 ;
    dist[start] = 0 ;
    pq.push(make_pair(dist[start],start));
    while( !pq.empty() ){
        pair<int,int> p = pq.top();
        pq.pop();
        int current_node = p.second;
        visit[current_node] = 1 ;
        for( auto e : g[current_node]){
            int to_node = e.first ;
            int to_weight = e.second ;
            if( visit[to_node] == 0 && to_weight < dist[to_node] ){
                dist[to_node] = to_weight ;
                pq.push(make_pair(dist[to_node],to_node));
            }
        }
    }
}
int main(){
    int n , m ,k ;
    cin >> n >> m  >> k ;
    vector<int>want ;
    for( int i = 0 ; i < k ; i++){
        int x ;cin >> x ;
        want.push_back(x);
    } 
    sort(want.begin(),want.end());
    for( int i =0 ; i < m ; i++){
        int u , v , w ;
        cin >> u >> v >> w ;
        g[u].push_back(make_pair( v,w));
        g[v].push_back(make_pair( u,w));
    }
    int min = 1e9 ;
    do{
        vector<int> visit(600,0);
        vector<int>dist(600,1e9);
        solve( want[0] ,dist,visit);
        int sum = 0 ;
        for( int i = 1 ;  i < want.size() ; i++ ){  
            sum += dist[want[i]];
        }
        if( sum < min ){
            min = sum ;
        }

    }while( next_permutation(want.begin(),want.end()));
    cout << min ;
}
    
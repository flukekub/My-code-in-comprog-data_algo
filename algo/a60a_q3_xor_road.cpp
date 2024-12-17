#include<bits/stdc++.h>
using std::vector;
using std::pair;
using std::make_pair;
using std::cin ;
typedef long long ll ;
ll w[2500] ;
vector<pair<ll,ll>> g[2500];
vector<ll> visit(2500,0);
vector<ll>dist(2500,-1e9);
std::priority_queue<pair<ll,ll> ,vector<pair<ll,ll>>,std::less<>>pq ;
ll n ;

void solve( ll start ){
    visit[start] = 1 ;
    dist[start] = 0 ; 
    pq.push( make_pair(dist[start],start));
    while( !pq.empty()){
        pair<ll,ll> p = pq.top();
        pq.pop();
        ll current_node = p.second ;
        ll current_weight = p.first ;
        visit[current_node] = 1;
        for( auto e : g[current_node]){
            ll to_node = e.first;
            ll to_weight = e.second ;
            if(  to_weight > dist[to_node] && visit[to_node] == 0 ){
                dist[to_node] = to_weight ;
                pq.push( make_pair( dist[to_node],to_node));
            }
        }
    }
}

int main(){
    
    cin >> n ;
    for( int i = 1 ; i<= n ; i++){
        cin >> w[i] ;
    }
    for( ll i = 1 ;  i <= n ;i ++ ){
        for( ll j = i+ 1 ; j <= n ; j++){
            g[i].push_back(make_pair(j,w[i] ^ w[j]));
            g[j].push_back(make_pair(i,w[i] ^ w[j]));
        }
    }
    solve(1);
    ll sum = 0 ;
    for( int i = 1 ; i <= n ; i++ ){
        sum += dist[i];
    }
    std::cout<<sum;
}
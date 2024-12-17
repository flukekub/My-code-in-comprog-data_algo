#include<bits/stdc++.h>
typedef long long ll ;
using std::vector;
using std::pair;
using std::make_pair;
using std::cin ;
vector<ll> g(2500);
vector<ll> visit(2500,0);
vector<ll>dist(2500,-1e9);
std::priority_queue<pair<ll,ll> ,vector<pair<ll,ll>>,std::less<>>pq ;
ll n ;
ll sum = 0 ;
void solve( ll start ){
    visit[start] = 1 ;
    dist[start] = 0 ;
    pq.push(make_pair( dist[start],start));
    while( !pq.empty()){
        pair<ll,ll> p = pq.top();
        pq.pop();
        ll current_node = p.second;
        visit[current_node] = 1 ;
        
        for( ll  i = 1 ; i <= n ; i++ ){
          if( i == current_node)continue ;
            if( (g[current_node] ^ g[i]) > dist[i] && visit[i] == 0 ){
                dist[i] = g[current_node] ^ g[i] ;
                
                pq.push( make_pair( dist[i],i));
            }
        }
    }
}

int main(){
    
    cin >> n ;
    for( ll i = 1 ; i <= n ; i++){
        cin >> g[i];  
    }
    solve(1);
    for( int i =1 ; i <= n ; i++ ){
        sum += dist[i];
    }
    std::cout<<sum;
}
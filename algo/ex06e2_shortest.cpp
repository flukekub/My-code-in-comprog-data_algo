#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>>g[100];
int dist[100][100];
bool neg = false ;
void solve( ){
    for( int k = 0 ; k < n ; k++){
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++){
                dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }
    for( int i = 0 ; i< n ; i++){
        if( dist[i][i]  < 0 ){
            neg = true ;
        }
    }
}


int main(){
  int e,s ;
  cin >> n >> e >> s  ;
    for(int i =0 ; i < n ; i++){
        for( int j = 0 ; j < n ; j++){
            if( i == j ){
                dist[i][j] = 0 ;
                continue;
            }
            dist[i][j] = 69696969;
        }
    }

  for( int i = 0 ; i < e ; i++){
    int  u , v , w ;
    cin >> u >> v >> w ;
    dist[u][v] = w;
    g[u].push_back(make_pair(v,w));
  }
    solve();
    if( neg ){
        cout << -1 ;
        return 0;
    }

    for( int i = 0 ; i < n ; i++ ){
        cout << dist[s][i] << " ";
    }
}
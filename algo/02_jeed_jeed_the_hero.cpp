#include<bits/stdc++.h>
using std::vector;
using std::pair;
using std::cin;
using std::cout;
using std::queue;
using std::map;
using std::make_pair;

int arr[2000][2000];
vector<int> tmp ( 2000,-1);
vector<vector<int>> dist(2000,tmp);
int visit[2000][2000];
map<pair<int,int>,vector<pair<int,int>>> m ;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int sum = 0 ;
void bfs(int a ,int b ){
    
    queue<pair<int,int>> q ;
    q.push(make_pair(a,b));
    dist[a][b] = 0;
    while (q.size() > 0){
        pair<int,int> u  = q.front();
        q.pop();
        visit[u.first][u.second] =1 ;
        for (auto e : m[u]){
            if (dist[e.first][e.second] == -1 && visit[e.first][e.second] == 0 ){
                
                dist[e.first][e.second] = dist[u.first][u.second] + 1;
                if( arr[e.first][e.second] == 2 ){
                    sum +=  dist[e.first][e.second] * 2 ;
                    dist[e.first][e.second] = 1 ;
                }
                q.push( make_pair(e.first,e.second));
            }
        }
    }
    
    
}

int main(){
    int R , C ;
    cin >> R >> C ;
    for( int i = 0 ; i < R ; i++ ){
        for( int j = 0 ; j < C ; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0 ;  i< R ; i++){
        for( int j = 0 ;  j< C ; j++ ){
            if( arr[i][j] == 1 ){
                for (int k = 0; k < 4; k++) {
                    int toi = i + dx[k];
                    int toj = j + dy[k];
                    if( toi  >= 0  && toj >= 0 && toi < R  && toj < C && arr[toi][toj] != 0 ){
                        m[{i,j}].push_back({toi,toj});
                    }
                }
            }
        }
    }
    bfs( 0,0);
    cout << sum ;
}
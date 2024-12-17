#include<bits/stdc++.h>
using namespace std;
int R , C ;
int a[8000][6000];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<>> q ;

int  bfs( int sx ,int sy , vector<vector<int>> & visit , int & min,vector<vector<int>>& dist ){
    visit[sx][sy] = 1 ;
    q.push(make_pair(1,make_pair(sx,sy)));
    dist[sx][sy] = 1 ;
    while( !q.empty()){
        pair<int,pair<int,int>> p = q.top();
        q.pop();
        pair<int,int> current_node = p.second;
        int current_weight = p.first ;
        visit[current_node.first][current_node.second] = 1 ;
        for( int i = 0 ; i < 4 ; i++ ){
            int to_x = current_node.first + dx[i];
            int to_y = current_node.second + dy[i];
            if( to_x >= 0  && to_y >= 0 && to_x < R && to_y < C && a[to_x][to_y] != 3 && visit[to_x][to_y] == 0 ){
                if( 1 + current_weight < dist[to_x][to_y] ){
                    
                    dist[to_x][to_y] = 1 + current_weight ;
                    if( a[to_x][to_y] == 2 && dist[to_x][to_y] < min ){
                        min = dist[to_x][to_y];
                    }
                    q.push( make_pair(dist[to_x][to_y] ,make_pair( to_x,to_y) ));
                }
            }
        }
    }
    return min ;
}

int main(){
    
    cin >> R >> C;

    set<pair<int,int> >s ;

    for( int i = 0 ; i < R ; i++){
        for( int j = 0 ; j < C ; j++){
            cin >> a[i][j];
            if( a[i][j] == 1 ){
                s.insert( make_pair(i,j));
            }
        }
    }
    
    
    int min = 1e9 ;
    int ans = min ;
    for( auto e : s ){
        vector<int>tmp(10000,1e9);
        vector<vector<int>> dist(10000,tmp); 
        vector<int>tmm( 10000,0);
        vector<vector<int>> visit(10000,tmm);
        int xx = bfs( e.first,e.second , visit ,min,dist) ;
        if(  ans >  xx ){
            ans = xx ;
        }
    }
    cout << ans ;
}
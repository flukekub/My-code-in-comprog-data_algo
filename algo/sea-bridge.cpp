#include<bits/stdc++.h>
using namespace std;
int R , C ;
int a[6000][6000];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<>> q ;

int  bfs(  vector<vector<int>> & visit , int & min,vector<vector<int>>& dist ){
    
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

    

    for( int i = 0 ; i < R ; i++){
        for( int j = 0 ; j < C ; j++){
            cin >> a[i][j];
            if( a[i][j] == 1 ){
                q.push( make_pair(1,make_pair(i,j)));
            }
        }
    }
    
    
    int min = 1e9 ;
    int ans = min ;
    
        vector<int>tmp(6000,1e9);
        vector<vector<int>> dist(6000,tmp); 
        vector<int>tmm( 6000,0);
        vector<vector<int>> visit(6000,tmm);
        int xx = bfs(  visit ,min,dist) ;
        
    cout << xx ;
}
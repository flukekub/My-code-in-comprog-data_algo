#include<bits/stdc++.h>
using std::pair ;
using std::priority_queue;
using std::vector;
using std::make_pair;

int R ,C ;
int a[500][500];
int dx[4] = { 0 , 0 , -1 , 1 }; 
int dy[4] = { -1 , 1 , 0 , 0};
vector<int> tmp(500,1e9);
vector<vector<int>>dist(500,tmp);
int visit[500][500] ;
priority_queue< pair< int,pair<int,int> >, vector<pair< int,pair<int,int> >>,std::greater<> > pq; 

void solve( int sx,int sy ){
    dist[sx][sy] = 0 ;
    visit[sx][sy] =1 ;
    pq.push( make_pair( 0 ,make_pair(sx,sy)));
    while( !pq.empty()){
        pair<int,pair<int,int>> p = pq.top();
        pq.pop();
        pair<int,int> current_node = p.second ;
        int current_weight = p.first;
        visit[current_node.first][current_node.second] = 1 ;
        for( int i = 0 ; i< 4 ; i++ ){
            int to_x = current_node.first + dx[i]; int to_y = current_node.second + dy[i];
            if( to_x >= 0  && to_x < R && to_y >= 0 && to_y < C ){
                if( current_weight + a[to_x][to_y] < dist[to_x][to_y] && visit[to_x][to_y] == 0 ){
                    dist[to_x][to_y] = current_weight + a[to_x][to_y] ;
                    pq.push( make_pair( dist[to_x][to_y], make_pair(to_x,to_y)));
                }
            }
        }


    }
}

int main(){
    
    std::cin >> R >> C ;
    
    for( int i =0 ; i < R ; i++){
        for( int j =0 ; j < C ; j++){
            std::cin >> a[i][j] ;
        }
    }
    solve( 0 , 0 );
    for( int i =0 ; i < R ; i++){
        for( int j =0 ; j < C ; j++){
            std::cout << dist[i][j]  << " ";
        }
        std::cout << "\n";
    }
}
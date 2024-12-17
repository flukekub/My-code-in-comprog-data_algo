#include<bits/stdc++.h>
using std:: cin ;
using std::cout ;
using std::queue;
using std::pair;
using std::make_pair;
using std::vector ;

int dx[4] = { 0 ,0 , -1, 1};
int dy[4] = { -1 ,1 , 0, 0};
int R , C , l ;
int a[ 1005][1005];
queue<pair<int,pair<int,int>>> q;
vector<vector<int>> visit( 1004 , vector<int> ( 1005,0));
vector<vector<int>> dist( 1004 , vector<int> ( 1005,1e9));
void dfs( ){
    while( !q.empty()){
        pair<int,pair<int,int>> p = q.front();
        q.pop();
        int current_weight = p.first ;
        visit[(p.second).first][(p.second).second] = 1 ;
        for( int i = 0 ; i < 4 ; i++ ){
            int toi = (p.second).first + dx[i];
            int toj = (p.second).second + dy[i];
            if(  toi  <= 0  || toi > R || toj <= 0 || toj > C || visit[toi][toj] == 1  ){
                continue;
            }
            if( visit[toi][toj] == 0 && 1 + current_weight < dist[toi][toj] && 1 + current_weight <= l  ){
                dist[toi][toj] = 1 + current_weight;
                if( a[toi][toj] == 0 ){
                    a[toi][toj] = 2 ;
                }
                q.push( make_pair( dist[toi][toj], make_pair(toi,toj)));
            }
        }
    }
}

int main(){
    cin >> R >> C >> l ;
    for( int i = 1 ; i <= R ; i++){
        for( int j = 1 ; j <= C ; j++){
            cin >> a[i][j];
            if( a[i][j] == 1 ){
                visit[i][j] = 1 ;
                dist[i][j]= 0 ;
                q.push(make_pair( 0 , make_pair(i,j)));
            }
        }
    }
    dfs();
    for( int i = 1 ; i <= R ; i++){
        for( int j = 1 ; j <= C ; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}
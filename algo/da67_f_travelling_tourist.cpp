#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dist( 505 , vector<int>(505,1e9));
void f(int n  ){
    for( int k =1  ; k <= n ; k++ ){
        for( int i =1  ; i <= n ; i++ ){
            for( int j =1  ; j <= n ;j++ ){
                dist[i][j] = min( dist[i][j],dist[i][k]+ dist[k][j]);
            }
        }
    }
}
int main(){
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<int> want ;
    for( int i = 0 ; i < k ; i++){
        int x ; cin>> x ;
        want.push_back(x);
    }
    sort(want.begin(),want.end());
    for( int  i = 1 ; i <= n ; i++){
        dist[i][i] = 0 ;
    }
    for( int i =0 ; i < m ; i++){
        int u , v , w ;
        cin >> u >>  v >> w ;
        dist[u][v] = w ;
        dist[v][u] = w ;
    }
    f(n);
    int min = 1e9 ;
    do{
        int sum = 0 ;
        for( int i = 0  ; i < want.size( )-1 ; i++){
            sum += dist[want[i]][want[i+1]];
        }
        if( sum < min ){
            min = sum ;
        }
    }while( next_permutation(want.begin(),want.end()));
    cout << min ;
}
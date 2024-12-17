#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[25];
vector<int> v ;
vector<bool>cv(8,false);

void search( int start,vector<int> &visit ,int sum ){
    visit[start] = 1 ;
    for( int i = 0 ; i < 8 ; i++ ){
        if( v[i] == sum ){
            cv[i]=true ;
        }
    }
   for (auto e : g[start]) {
        if (visit[e.first] == 0) {
            visit[e.first] = 1; // Mark as visited
            search(e.first, visit, sum + e.second);
            visit[e.first] = 0; // Backtrack
        }
    }
}



int main(){
    int n , m ;
    cin >> n >> m ;
    
    for( int i = 0 ; i < 8 ; i++){
        int x ;
        cin >> x; 
        v.push_back(x);
    }
    for( int i =0 ; i < m ; i++){
        int u , v , w ;
        cin >> u >> v >> w;
        g[u].push_back( make_pair(v,w));
        g[v].push_back( make_pair( u,w));
    }
    
    for( int i = 0 ; i < n ; i++){
        
        vector<int> visit(25,0);
        int sum = 0 ;
        search(i,visit,sum);
    }
    for( int i = 0 ; i< 8 ; i++){
        if( cv[i] == true ){
            cout << "YES" << '\n';
        }else{
            cout << "NO"<<"\n";
        }
    }
}
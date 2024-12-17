#include<bits/stdc++.h>
using std::vector ;
using std::map ;
using std::pair ;
using std:: set ;
using std::cin ;
using std::cout ;
using std::make_pair;

vector<int> v[10000];
vector<int> cost(10000,INT16_MAX);
vector<int> taken(100000,0);
int n ;
map<pair<int,int>,int> m ; 
vector<int> prev(100000,-1);

void prim(   ){
    set<pair<int,int>> s ;
    s.insert({ 0, 0});
    while( !s.empty()){
        pair<int,int> p = *s.begin() ;
        s.erase(*s.begin());
        taken[p.second] = 1 ;
        for( auto e : v[p.second]){
            if( cost[e] > m[{e,p.second}] && taken[e] == 0 ){
                s.erase( {cost[e], e });
                cost[e] = m[{e,p.second}];
                
                s.insert( { cost[e],e});
            }
        }
    }
}

int main(){
    
    cin >> n ;
   
    for( int i = 0  , k = n-1; i < n-1 ; i++,k-- ){
        for( int j = k ,idx = 0 ; j > 0 ; j--,idx++  ){
            int x ;cin >> x ;
            m[make_pair( i+idx +1 ,i)] = x ;
            m[make_pair( i,i+idx +1 )] = x ;
            v[i+idx+1].push_back(i);
            v[i].push_back(i+idx+1);
        }
    }
    prim();
    int sum = 0 ;
   for( int i = 1 ; i < n ; i++ ){
     sum += cost[i] ;
   }
   cout << sum ;
}
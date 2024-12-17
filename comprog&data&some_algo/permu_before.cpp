#include<bits/stdc++.h>
using namespace std ;
 
vector<pair<int,int>> condition ;


bool check( vector<int> &sol , int len ){
    bool tick = true ;
    for( auto e : condition ){
        for( int i = 0 ; i < len ; i++ ){
            if( sol[i] == e.first ){
                for( int j = 0 ; j != i && j < len ; j++ ){
                    if( sol[j] == e.second){
                        ( i < j )? tick = true : tick = false ;
                        break ;
                    }
                }
                if( tick ){
                    continue ;
                }
            }
            
        }
    }
    
}


void perm(int n,vector<int> &sol,int len,vector<bool> &used) {
    bool wrong = check( ) ;

    if (len < n && ! wrong ) {
        
        for (int i = 1;i<=n;i++) {
            if (used[i] == false) {
                used[i] = true;
                sol[len] = i;
                perm(n,sol,len+1,used);
                used[i] = false;
            }
        }
    } else {
        for (auto &x : sol) cout << x;
            cout << endl;
    }
}


int main(){
   
    vector<int> v;
   
    int n ,m ;
    cin >> n ;
    cin >> m ;
    while( m-- ){
        int x , y ;
        cin >> x >> y ;
        condition.push_back(make_pair(x,y));
    }

    
    
      
    

}
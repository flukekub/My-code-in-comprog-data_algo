#include<bits/stdc++.h>
using namespace std ;

bool  cycle(int a , vector<int> &visit ,int parent , vector<int> v[1000] ,bool & f   ){
    visit[a] = 1 ;
    for( auto e : v[a]){
        if( visit[e] == 0 ){
            cycle( e , visit , a , v , f);
        }else if( e != parent ){
            f = true  ;
        }
    }
    return f ;
}
bool check( vector<int> v[1000] , int n ){
    vector<int> visit(n,0);
    for( int i = 0 ; i < n ; i++ ){
        if( visit[i] == 0 ){
            bool f = false ;
            if( cycle( i, visit , -1 , v , f)){
                return true ;
            }
        }
    }
    return false ;
}
int main(){
   

    int number_of_graph ;
    cin >> number_of_graph ;
    
    for( int i = 0 ; i < number_of_graph ; i++  ){
        int n ,e; 
        cin >> n >> e  ;
        vector<int> v[1000];
        for( int  j = 0 ; j < e ; j++ ){
            int x , y ;
            cin >> x >> y ;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if( check( v,n ) ){
            cout << "YES\n" ;
        }else{
            cout << "NO\n";
        }

    }
    
}
#include<bits/stdc++.h>
using namespace std ;
set<int> child ;
int n ;
void findchild( int m ){
    if( m >= n ){
        return ;
    }

    child.insert( m );
    return findchild( 2*m +1 ),findchild( 2*m + 2 ) ;
}


int main(){
    int m ;
    cin >> n >> m ;
    findchild( m );
    /*for( auto e : child ){
        cout <<  e << " " ;
    }*/

   cout << n - child.size() << "\n";
   for( int i = 0 ; i < n ;i++ ){
        if( child.find( i ) == child.end()) {
            cout << i << " " ;
        }
   }
}
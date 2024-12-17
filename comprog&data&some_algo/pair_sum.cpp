#include<bits/stdc++.h>
using namespace std ;
int main(){
 
  int n , m ;
  cin >> n >> m ;
  set<int> s ;
  for(int i = 0 ; i < n ; i++){
    int sum ;
    cin >> sum ;
    s.insert( sum ) ;
  }
  int want ;
  while( m-- ){
    bool found = false ;
    cin >> want ;
    for( auto e : s ){
      if ( s.find( want - e) != s.end()  && e != want-e ){
        found = true ;
        break;
      }
    }
    if( found ){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n" ;
    }
  }
}
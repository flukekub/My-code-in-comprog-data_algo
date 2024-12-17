#include<bits/stdc++.h>
using namespace std ;
map<int , vector<int> >  m ;
bool find_warp(int a,int b){
    if( a ==  b  ){
        return true ;
    }

    for( auto e : m[a] ){
       if ( find_warp( e , b ) ){
         return true ;
       }
    } 
    return false ;
}
int main(){
   int n , a, b ;
   cin >> n >> a >>  b ;
   while( n-- ){
     int x , y ;
     cin >> x >> y ;
     m[x].push_back(y) ;
   }
   if( find_warp( a, b )){
    cout << "yes";
   }else{
    cout << "no" ;
   }
    
}
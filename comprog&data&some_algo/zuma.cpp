#include<bits/stdc++.h>
using namespace std;
list<int> zuma (  list<int>::iterator it , int colour , list<int> & l ){
    
    auto left = prev(it) ;
    int count = 1 ;
    while( left != l.end() && *left == colour){
        count++ ;
        left--;
    }
    auto right = next(it) ;
    while( right != l.end() && *right == colour){
        count ++;
        right++;
    } 

    if( count < 3 || l.empty() ){
        return l ;
    }

    list<int>::iterator  memitr ; 
    if( count >= 3 ){
        memitr = l.erase(next(left) , right);
        memitr-- ;
        return  zuma( memitr , *memitr , l)  ;
    }
}


int main(){
    int N , K , V ;
    cin >> N >> K >> V ;
    list<int> l ,answer ;
    while( N-- ){
        int x ;
        cin >> x ;
        l.push_back(x);
    }
    
    auto it = l.begin();
    for( int i =0  ; i < K ; i++){
        it++ ;
    }

    it = l.insert( it, V );
    

    answer = zuma( it , V , l );

    for( auto e : answer){
        cout << e << " ";
    }
    
}
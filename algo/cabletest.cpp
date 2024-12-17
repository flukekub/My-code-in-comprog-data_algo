#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> m ;
int solve( int n ){
    vector<bool> visited(n,false);
    vector<unsigned long > minWeight(n,0);
    int totalBeauty =0 ;
    visited[0] = true ;
    for( int i = 1 ; i < n ; i++){
        minWeight[i] = m[{0,i}];
    }
    for( int e = 0 ; e < n-1 ; e++){
        int minEdge = 696969 ,nextNode = -1 ;
        for( int i = 0 ; i < n ; i++ ){
            if( !visited[i] && minWeight[i] < minEdge ){
                minEdge = minWeight[i];
                nextNode = i ;
            }
        }

        visited[nextNode] = true ;
        totalBeauty += minEdge;

        for( int i = 0 ; i < n ; i++){
            if( !visited[i]){
                int xorVal = m[{nextNode,i}];
                if( xorVal < minWeight[i]) minWeight[i] = xorVal;
            }
        }
    }
    return totalBeauty ;
}





int main(){
    int n ;
    cin >> n ;
    
    for( int i = 0 , ii = n-1 ; i < n-1 ; i++,ii-- ){
        for( int j = ii , k = 0  ; j > 0 ; j--,k++ ){
            int x ;cin >> x ;
            m[make_pair(i,i+k+1)] = x;
            m[make_pair(i+k+1,i)] = x;
        }
    }
    cout << solve(n) ;
}
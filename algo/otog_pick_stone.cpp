#include<bits/stdc++.h>
using namespace std ;
 int a[100] ;
 int n ;
 int sumall = 0 ;
int mem[100][100];
bool vis[100][100];


int solve(int left , int right ){
    if( left > right ){
        return 0 ;
    }
    if( vis[left][right] == true ){
        return mem[left][right];
    }
    vis[left][right] = true ;
    
    int case1 = solve( left+1 , right-1 ) + a[left];
    int case2 = solve( left+1,right -1 ) + a[right];
    int case3 = solve( left+2,right) + a[left];
    int case4 = solve( left , right -2 )+ a[right];
    
    mem[left][right] = max( { case1 , case2,case3,case4});
    return max( { case1 , case2,case3,case4})  ;
}




int main(){
    
    cin >> n ;
   
    for( int i = 0 ; i <  2*n ; i++ ){
        cin >> a[i];
        sumall += a[i] ;
    }
    cout << solve( 0,2*n-1);
}
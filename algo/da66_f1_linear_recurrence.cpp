#include<bits/stdc++.h>
using namespace std;
#define moder %32717 ;
int c[1001];
int a[1001];
vector<int> mem(1005,-1);
int  k ;
int R( int n ){
    if(  n < k  ){
        return a[n];
    }
    if( mem[n] != -1 ){
        return mem[n];
    }
    int sum = 0 ;
    for( int i = 1 ; i <= k ; i++ ){
        sum += ((c[i]  )*(R(n-i) ));
        sum = sum ;
    }
    mem[n] = sum  ;
    return mem[n];
}



int main(){
    int  n ; 
    cin >> k >> n ;
    for( int i = 1 ; i <= k ; i++ ){
        cin >> c[i];
    }
    for( int i = 0 ; i < k ; i++){
        cin >> a[i];
    }
    
    cout << R(n) ;
}
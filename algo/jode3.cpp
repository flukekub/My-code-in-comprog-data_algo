#include<bits/stdc++.h>
using namespace std ;
int moder = 1e8+7 ;
int main(){
    int n ;cin >> n ;
    int a[1000000];
    a[1] = 3 ;
    a[2] = 7 ;
    a[3] = 9 ;
    for( int i = 4 ; i<= n ;i++){
        a[i] = a[i-1] * 2 % moder+ a[i-3] % moder;
        a[i] = a[i]% moder ;
    }
    cout << a[n]  ;
    
}
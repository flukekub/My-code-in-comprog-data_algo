#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long int n ;
    cin >> n ;
    vector<int> a(n+2) ;
    long long int moder = 1e9 + 7 ;

    
    a[1] = 1 ;
    a[2] = 3 ;
    a[3] = 5 ;
    for( int i = 4; i <=n ; i++){
        a[i] = (a[i-1] % moder + (2*a[i-2] )%moder)%moder;
    }
    cout << a[n];

}
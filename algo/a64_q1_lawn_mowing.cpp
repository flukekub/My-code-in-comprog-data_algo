#include<bits/stdc++.h>
using namespace std ;
int main(){
    
    typedef long long int ll ;
    ll n , m , k ;
    cin >> n >> m >> k ;
    vector<ll> a(n+1);
    a[0] = 0 ;
    for( ll i = 1 ; i <= n ; i++ ){
        ll x ;
        cin >> x ;
        a[i] = a[i-1]+ x + k  ;  
    }

    for( ll i = 0 ; i < m ;i++ ){
        ll x , y ;
        cin >> x >> y ;
        
        auto it = upper_bound( a.begin(),a.end() , y+a[x])  ;
        it--;
        cout << *it -  a[x] - ((it - a.begin() - x) * k)<<"\n";
    }
}
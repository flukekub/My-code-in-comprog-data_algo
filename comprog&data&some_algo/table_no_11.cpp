#include<bits/stdc++.h>
using namespace std;





int main(){
    long long  n ;
    cin >> n;
    long long int a[n+1];
    
    a[1] = 3 ;
    a[2] = 7 ;
    for( int i = 3 ; i < n+1 ; i++ ){
        a[i] = ((2*a[i-1])%  100000007 + (a[i-2])%  100000007)%  100000007;
    }
    cout << a[n] %  100000007 ;
}
//2119547
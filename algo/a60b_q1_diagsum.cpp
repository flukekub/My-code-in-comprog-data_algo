#include<bits/stdc++.h>
using namespace std;





int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    vector< vector<int> > a( n,v) ;
    int max = 0 ;
    for( int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            cin >> a[i][j];
            if(  i == 0 || j == 0 )continue;
            if( a[i-1][j-1] > 0 ){
                a[i][j] += a[i-1][j-1];
            }
            if( a[i][j] > max ){
                max = a[i][j];
            }
        }
    }
       
    cout << max ;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int f ,w , n ;
    cin >> f >> w >> n ;
    vector<int> v; 
   
    for( int i = 0 ; i < f ; i++ ){
        int x ;cin >> x;
        v.push_back(x);
    }
   
    sort( v.begin(),v.end());
    int table = v[0] ;
    int idx_v = 0 ;
    int count = 0 ;
    while( idx_v < v.size()){
        count++;
        int tmp = table + 2 *w ;
        idx_v = upper_bound(v.begin(),v.end() ,tmp) - v.begin();
        table = *upper_bound(v.begin(),v.end() ,tmp);
    }
    cout << count ;
}
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m , k , w ;
    cin >> n >> m >> k >> w ;
    vector<int> p ;
    vector<int> h ;
    vector<int> t ;
    for( int i = 0 ; i < m ; i++ ){
        int x ;
        cin >> x ;
        p.push_back(x);
    }
    for( int i = 0 ; i < m ; i++ ){
        int x ;
        cin >> x ;
        h.push_back(x);
    }
    for( int i = 0 ; i < k ; i++){
        int x ;
        cin >> x ;
        t.push_back(x);
    }
    sort( p.begin(),p.end());
    sort( h.begin(),h.end());
    sort( t.begin(),t.end());
    vector<int> used(k,0) ;
    /*attack*/
    
        for( int i = h.size() -1  ; i >= 0 ; i--){
            for( int j = 0 ; j <t.size() ; j++ ){
                if( p[i] <= t[j] + w &&  p[i] >= t[j] - w && used[j] == 0 ){
                    if( h[i] > 0 ){
                        h[i]-- ;
                        used[j] = 1 ;
                    }
                }
            }
        }
    


    int sum = 0 ;
    for( int i = 0 ; i < m ; i++ ){
        sum += h[i] ;
    }
    cout << sum ;
}
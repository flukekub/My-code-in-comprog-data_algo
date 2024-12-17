#include<bits/stdc++.h>
using namespace std ;
int main(){
    int k ; 
    cin >> k;
    int x ;
    set<int> set ;
    int count = 0 ;
    while (cin >> x ){
        set.insert(x);
    }
    for(int i = 0 ; i <= k/2 ;i++){
        if( set.find(i) != set.end()  &&  set.find(k-i) != set.end() && set.find(i) != set.find(k-i)){
            count++ ;
        }
    }
    cout << count ;
}
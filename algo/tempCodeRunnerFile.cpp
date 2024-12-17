#include<bits/stdc++.h>
using namespace std ;

int moder = 1e9 + 7  ;
vector<int> mem(10,-1) ;
int  solve( vector<int> v , int n ){

    if( mem[v.size()] != -1 ){
        return mem[v.size()];
    } 
    if( v.size() == n ){
        bool tick = true ;
        for( int i = 0 ; i < v.size() ; i++){
            if( v[i] == 1 ){
                if( v[i-2] == 2  && i- 2  >= 0 ){
                    tick = false ;
                }
                if( v[i-1] == 2 &&  i-1 >= 0 ){
                    tick = false ;
                }
                if( v[i+1] == 2 && i+1 < v.size() ){
                    tick = false ;
                }
                if( v[i+2] == 2 && i+2 < v.size() ){
                    tick = false ;
                }
                
            }
        }
        if( tick ){
            return  1;
        }
        return 0 ;
    }
    int sum1 = 0 , sum2 = 0 , sum3 = 0 ; 
    v.push_back(0);
    sum1  = solve(v ,n);
    v.pop_back();

    v.push_back(1);
    sum2 = solve(v ,n);
    v.pop_back();

    v.push_back(2);
    sum3 =  solve(v ,n);
    v.pop_back();

    return  (sum1 % moder +sum2% moder + sum3% moder)% moder ;
    
}


int main(){
    vector<int> v ;
    int n ; cin >> n ;
    
    
    cout << solve(v,n) ;
}
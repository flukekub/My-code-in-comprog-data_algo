#include<bits/stdc++.h>
using std::cin ;
using std::vector;
typedef long long ll ;
ll R , C ;
ll a[600][600];
ll moder = 1e8 + 7 ;
vector<ll> tmp1(4,-1);
vector<vector<ll>> tmp2(600,tmp1);
vector<vector<vector<ll>>> mem(600,tmp2);



ll solve ( ll ati,ll atj , char move ,char prev_move){
    if( a[ati][atj] == 1 || move == prev_move || ati < 1 || ati > R || atj < 1 || atj > C  ){
        return 0 ;
    }
    std::cout << ati << " " << atj  << " --> "; 
    if( atj == C ){
        return 1 ;
    }
    int type_move ;
    
    if( move == 'x'){
        type_move = 1 ;
    }
    if( move == 'y'){
        type_move = 2 ;
    }
    if( move == 'z'){
        type_move = 3 ;
    }
    

    if (mem[ati][atj][type_move] != -1) {
        return mem[ati][atj][type_move];
    }
    ll count = 0 ;
    count = (count + solve( ati -1 ,atj+1 ,'x',move))%moder;
    count = (count + solve( ati  ,atj+1 ,'y',move))%moder;
    count =(count + solve( ati +1 ,atj+1 ,'z',move))%moder;

    mem[ati][atj][type_move] = count;
    return count;
}


int main(){
    
    cin >> R >> C ;
    for( ll i = 1 ; i <= R ; i++){
        for( ll j = 1 ; j <= C ; j++ ){
            cin >> a[i][j];
        }
    }
    int sum = 0 ;
    for( ll i = 1 ; i <= R ; i++ ){
        sum += solve( i,1,'w','u')  ;
        sum = sum % moder ;
    }
    std::cout <<  sum % moder;
}
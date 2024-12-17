#include<bits/stdc++.h>
using namespace std ;
int main(){
    string sum , n  ;
    cin >> sum ;
    while( cin >> n ){
        if( n == "END"){
            break;
        }
        int maxlak = max( sum.length(),n.length() );
        int minlak = min( sum.length(),n.length() );
        string s ;
        int rob = maxlak - minlak ;
        while( rob-- ){
            if( sum.length() <  n.length()){
                sum = "0" + sum ;
            }else{
                n = "0" + n ;
            }
        }
        string answer = "" ;
        bool tod  = 0 ;
        for( int i = n.length()-1 ;  i >= 0  ; i-- ){
            if( ( sum[i] - '0' ) + ( n[i] - '0' ) + tod < 10 ){
                answer = char(( sum[i] - '0' ) + ( n[i] - '0' ) +'0'+ tod ) + answer;
                tod = 0 ;
            }else{
                tod = 1 ;
                answer = char(( sum[i] - '0' ) + ( n[i] - '0' ) - 10 +'0' + tod ) + answer;
            }
        }

        sum = answer ;
    }
    cout << sum ;
}
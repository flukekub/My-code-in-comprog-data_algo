#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >>s;
    int n;
    cin >> n;
    while( n-- ){
        int index = s.length()-1;
        int tod =0 , sum;
        sum = s[index]-'0'+1;
        if( sum >= 10 ){
            tod = 1 ;
            s[index] = (sum - 10)+ '0' ;
        }else{
            s[index] = (sum)+ '0' ;
        }
        index--;
        while( s[index] != '-'){
            sum = s[index]-'0'+tod;
            if( sum >= 10 ){
                tod = 1 ;
                s[index] = (sum - 10)+ '0' ;
            }else{
                tod=0;
                s[index] = (sum)+ '0' ;
            }

            index--;
        }
        index--;
        if( tod == 1){
            if( s[index-1] != 'Z' || s[index] != 'Z'){
                if( s[index]!= 'Z'){
                    s[index]++;
                }else{
                    s[index-1]++;
                    s[index]= 'A';
                }
            }else{
                if( s[index-2] != '9'&&s[index]){
                    s[index -2]++;
                    s[index-1] ='A';
                    s[index] ='A';
                }else{
                    s = '1' + s;
                }
            }
        }

    }
    cout << s;
}
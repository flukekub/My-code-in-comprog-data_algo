#include<bits/stdc++.h>
using namespace std;

int count( string h){
    int counts=0;
    for(auto c : h){
        if( (c >= 'A' && c <= 'Z')|| (c >='a'&&c<='z')){
            counts++;
        }
    }
    return  counts ;
}

int main(){
    string hoax,counthoax;
    getline(cin,hoax);
    string s,ss,scheck="";
    string a[12] = {"UUUU","UUUL","UULU","UULL","ULUU","ULUL","ULLU","ULLL","LUUU","LUUL","LULU","LULL" };
    while( getline(cin,s)){
        
        if(s[0] == 'E'){
            string code = s.substr(2);
            ss = hoax;
            scheck="";

            for( auto c: code){
                if( c != '-' && c != ','){
                    scheck += a[c-'0'];
                }else if( c == '-' ){ 
                    scheck += a[10];
                }else if ( c == ','){
                    scheck += a[11];
                }
            }
            while( count(ss ) < 4*code.length() ){
                ss = ss+hoax;
            }
            int i , j;
            for(  i =0 ,j=0 ; i < scheck.length(); i++,j++){
                while( (ss[j] < 'A'|| ss[j] > 'Z')&&(ss[j] <'a'|| ss[j] > 'z') ){
                    j++;
                }
                if( scheck[i] == 'U' && (ss[j] >= 'a' && ss[j] < 'z') ){
                    ss[j] = ss[j] - 32 ; 
                }
                if( scheck[i] == 'L' && (ss[j] >= 'A' && ss[j] < 'Z') ){
                    ss[j] = ss[j] + 32 ; 
                }
            }

            cout << ss.substr(0,j) << "\n";
            




        }else if( s[0] == 'D'){
            string sentence = s.substr(2), sds ="";
            
            for( auto c : sentence){
                if( (c >= 'A' && c <= 'Z' )|| (c >= 'a' && c <= 'z')){
                    sds += c ;
                }
            }
            for( int i = 0 ; i < sds.length()  ; i++){
                
                if( sds[i] >= 'A' && sds[i] <= 'Z' ){
                    sds[i] = 'U';
                }else if( sds[i] >= 'a' && sds[i] <= 'z'){
                    sds[i] = 'L';
                }
                
            }
            for( int i = 0 ; i+3 < sds.length(); i += 4){
                for(int j = 0 ; j < 12 ;j++ ){
                    if(a[j] == sds.substr( i,4)){
                       if( j != 10 && j != 11){
                        cout << j ;
                       }else if ( j == 10){
                        cout << '-';
                       }else if ( j == 11 ){
                        cout << ',';
                       }
                    }
                }
            }  
            cout << "\n";
        }
    }
    
}
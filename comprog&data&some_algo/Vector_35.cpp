#include<bits/stdc++.h>
using namespace std ;
int main(){
    string s ;
    
    while(getline(cin ,s)){
        vector<string> kum ;
        if( s == "q"){
            break;
        }
        s = s +' ';
        string ss = "";
        for(int i = 0 ,pos = 0 ,count = 0 ; i < s.length() ; i++ ,count++ ){
            
            ss += s[i];
            if(s[i] == ' '){
                ss.pop_back();
                kum.push_back(ss);
                ss = "";
            }
        }
        vector<string> v  = { "soon", "neung", "song", "sam", "si", "ha", "hok", "chet", "paet", "kao"}; 
        vector<string> d = {   "sip", "roi", "phan", "muen", "saen","lan" };
        int total = 0 ,i ;

        if( kum[0] == "sip" && kum.size() == 1 ){
            cout << 10 << "\n";
            continue;
        }
        if( kum[0] == "sip"){
            for( int j = 0 ; j < v.size() ; j++){
                if( kum[1] == "et"){
                    cout << 10 + 1 << "\n"; 
                    break;
                }
                if( kum[1] == v[j]){
                    cout << 10 + j << "\n"; 
                    break;
                }
            }
            continue;
        }
bool tick = false ;
        for(  i =0 ; i < kum.size()-1 ; i+=2){
            int x ,y;
            for(int j = 0  ; j < v.size() ;j++ ){
                if( kum[i] == "sip" ){
                    x = 1 ;
                    y = 10;
                    break;
                }
                if( kum[i] == "yi"){
                    x = 2 ;
                }else if( kum[i] == v[j]  ){
                    x = j ;
                }

                if( kum[i+1] == d[j] &&  j < d.size() ){
                    y = pow(10,j+1) ;
                }
            }
            total += x*y;
        }
        
            for( int j = 0 ; j < v.size() ; j++){
                if( kum[kum.size()-1] == "sip" && kum.size() == 3 ){
                    total += 10;
                    break;
                }else if( kum[kum.size()-1] == "et"){
                    total += 1 ;
                    break;
                }else if( kum[kum.size()-1] == v[j]){
                    total += j ;
                }
            } 
        
         

        cout << total << "\n";


    }
    

}
#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n ;
    cin >> n ;cin .ignore();
    string s ;
    map<string,vector<string>> m ;
    while( n-- ){
        getline( cin , s );
        int i = 0 ;
        while ( i < s.length() && s[i] != ',' ){
            i++;
        }
        string song = s.substr(0,i);
        string singer = s.substr(i+2);

        m[song].push_back(singer);
        
    }   
    string findsong ;
    getline(cin , findsong );
    vector<string > answer ;
    for( int i = 0 ; i < findsong.length() ; i++ ){
        string ss = "";
        while( findsong[i] != ',' && i <findsong.length() ){
            ss += findsong[i];
            i++;
        }
        answer.push_back(ss);
        i = i+1 ;
    }
    for( auto e : answer ){
        cout << e << " -> " ;
        string sss = "";
        if( m[e].empty()){
            sss = "Not found   ";
        }
        for( auto c : m[e]){
            
            sss += c + ", ";
        }
        
        cout << sss.substr(0,sss.size() -2 )<< "\n" ;
    }
    
}
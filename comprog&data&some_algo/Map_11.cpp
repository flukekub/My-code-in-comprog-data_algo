#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n ; 
    cin >> n ;
    map<string,string> m ;
    while( n-- ){
        string jing , len ;
        cin >> jing>> len ;
        m[jing] = len ;
        m[len] = jing ;

    }
    string name ;
    int k ; 
    cin >> k ;
    while(  k-- ){
        cin >> name;
        if( m.find(name) == m.end()){
            cout << "Not found"<< "\n";
        }else{
            cout << m[name] << "\n";
        }
        
    }
}
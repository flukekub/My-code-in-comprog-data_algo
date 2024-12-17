#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n; cin.ignore();
    
    string s  ;
    map<string,string> m ;
    while(n--){
        
        getline(cin , s);
        string name = "" ,tel ;
        int i = 0 ,count = 0;
        while( count < 2){
            if( s[i] == ' '){
                count++;
            }
            i++;
        }
        name = s.substr(0,i-1);
        tel = s.substr(i);
        m[name] = tel ;
        m[tel] = name ;
    }
    int nn ;
    cin >> nn ; cin.ignore() ;
    string answer ;
    while( nn--){
        getline(cin,answer);
        cout << answer << " --> " ;
        if(  m.find(answer) != m.end() ){
            cout << m[answer] << "\n";
        }else{
            cout << "Not found" <<"\n";
        }
       
    }
}
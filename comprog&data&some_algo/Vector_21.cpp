#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<string> v;
    string s ;
    cin >> s;
    s = s + '$';
    v.push_back(s);
    while(s[0] != '$'){
        s = s.substr(1) + s[0];
        v.push_back(s);
    }

    sort( v.begin(),v.end());
    string answer="";
    for( auto e: v ){
        answer +=  e[e.length()-1]; 
    }

    cout << answer;
}
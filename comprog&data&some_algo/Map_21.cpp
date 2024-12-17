#include<bits/stdc++.h>
using namespace std ;
int main(){
    string name ,pan ;
    vector<string> v ;
    map <string ,vector<string>> m ;
    while (cin >> name >> pan ){
        if( find(v.begin(),v.end(),pan )  == v.end() ){
            v.push_back(pan);
        }
        
        m[pan].push_back(name);
    }
    for(auto e : v ){
        cout << e << ": " ;
        for(auto c : m[e]){
            cout << c << " " ;
        }
        cout << "\n";
    }
}
#include<bits/stdc++.h>
using namespace std ;
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    multiset<char> set1,set2 ;
    for(auto c : s1 ){
        if( c == ' '){
            continue;
        }else{
            if( c >= 'A' && c <= 'Z'){
                set1.insert(c + ('a'-'A'));
            }
            else{
                set1.insert(c);
            }
        }
    }
    for(auto c : s2 ){
        if( c == ' '){
            continue;
        }else{
            if( c >= 'A' && c <= 'Z'){
                set2.insert(c + ('a'-'A'));
            }
            else{
                set2.insert(c);
            }
        }
    }

    if( set1 == set2){
        cout << "YES";
    }else {
        cout<< "NO";
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    map < string , double > m  ;
    m["THB"] = 1 ;
    string sakul ;
    double chenge_to_bath ;
    while( n-- ){
        cin >> sakul >> chenge_to_bath ;
        m[sakul] = chenge_to_bath ;
    }
    int money ;
    cin >> money ;
    string f_sakul ;
    cin >> f_sakul ;

    cout <<  money << " " << f_sakul ;
    int chenge ;
    while( cin >> sakul ){
        chenge = (money *m[f_sakul]) / m[sakul] ;
        cout << " -> " << chenge << " " << sakul ;
        f_sakul = sakul ;
        money = chenge ;
    }
}
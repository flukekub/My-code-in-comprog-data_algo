#include<bits/stdc++.h>
using namespace std ;
string str ;
int main(){
    map<string , string > m ;
    m["0"] = " "; m[" "] = "0";

    m["2"] = "a"; m["a"] = "2";
    m["22"] = "b"; m["b"] = "22";
    m["222"] = "c"; m["c"] = "222";

    m["3"] = "d"; m["d"] = "3";
    m["33"] = "e"; m["e"] = "33";
    m["333"] = "f"; m["f"] = "333";

    m["4"] = "g";  m["g"] = "4";
    m["44"] = "h"; m["h"] = "44";
    m["444"] = "i"; m["i"] = "444";

    m["5"] = "j"; m["j"] = "5";
    m["55"] = "k"; m["k"] = "55";
    m["555"] = "l"; m["l"] = "555";

    m["6"] = "m"; m["m"] = "6";
    m["66"] = "n"; m["n"] = "66";
    m["666"] = "o"; m["o"] = "666";
    

    m["7"] = "p"; m["p"] = "7";
    m["77"] = "q"; m["q"] = "77";
    m["777"] = "r"; m["r"] = "777";
    m["7777"] = "s"; m["s"] = "7777";

    m["8"] = "t"; m["t"] = "8";
    m["88"] = "u"; m["u"] = "88";
    m["888"] = "v"; m["v"] = "888";

    m["9"] = "w";  m["w"] = "9";
    m["99"] = "x"; m["x"] = "99";
    m["999"] = "y"; m["y"] = "999";
    m["9999"] = "z"; m["z"] = "9999";

    string s ;
    while (getline( cin , s )){
        if( s.substr(0,3) == "T2K"){
            cout << ">> " ;
            for( int i = 4 ; i < s.length() ; i++){
                if( s[i] >= 'A' && s[i] <= 'Z'){
                   s[i] =  s[i] + 32 ; 
                }
                cout << m[ str.assign(1, s[i] )] << " " ;
            }
            cout << "\n";
        }else{
           
            cout << ">> ";
            for( int i = 4 ; i < s.length() ; i++){
                string sss = "" ;
                while( s[i] != ' ' && i < s.length() ){
                    sss += s[i] ;
                    i++;
                }
                cout << m[sss] ;
            }
            cout << "\n";

        }
        
    }
}
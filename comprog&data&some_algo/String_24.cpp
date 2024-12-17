#include<bits/stdc++.h>
using namespace std ;
int main(){
    string s ,sara1 = "" , sara2="",s1,s2,s3;    
   getline( cin ,s);
   int count2 = 0;
    int first ,findsara;
   for(  first = 0 ;  ; first++ ){
        if( s[first] == 'a'|| s[first] == 'e'||s[first] == 'i'||s[first] == 'o'||s[first] == 'u'){
            sara1 += s[first]; 
            findsara = first +1 ;
            while( s[findsara] != ' '){
                sara1 +=  s[findsara];   
                findsara++ ;
            }
            
            break;
        }
   }

    int last ;
   for( last = s.length()-1 ; ; last--){
        if( s[last] == ' '){
            break;
        }
   }
    int i ,findsara2;
   for(    i =last ;  ; i++ ){
        if( s[i] == 'a'|| s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'){
            sara2 += s[i]; 
            findsara2 = i +1 ;
            while( findsara2 < s.length()){
                sara2 +=  s[findsara2];   
                findsara2++ ;
            }
            
            break;
        }
   }

   s1 = s.substr( 0 , first);
   s2 = s.substr( findsara  , i-findsara );
   

   
   
   
   cout << s1 + sara2 + s2+sara1;

}   
   

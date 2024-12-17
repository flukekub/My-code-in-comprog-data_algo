#include<bits/stdc++.h>
using namespace std ;

bool checkvirus( int left , int right , vector<int>& v   ){
    int mid = (left + right )/2 ;
    int countleft = 0 ;
    for( int i = left ; i <= mid; i++ )
        if( v[i] == 1 )countleft++ ;
    int countright = 0 ;
    for( int i = mid+1 ; i <= right; i++ )
        if( v[i] == 1 )countright++ ;

    
    if( abs( countleft - countright)  > 1  ){
        return false ; 
    }else{
        if( right - left > 3 )
            return checkvirus( left ,mid , v ) && checkvirus( mid +1 ,right , v );

        return true ;
    }
        

   
}



int main(){
    int n , k ;
    cin >> n >> k;
    while( n--){
        vector<int> v ;
        for( int i = 0 ; i < pow(2,k); i++ ){
            int bit ;
            cin >> bit ;
            v.push_back(bit);
        }
        if( checkvirus( 0, v.size()-1, v ))cout << "yes" <<"\n";
        else cout << "no" << "\n"; 

    }
}
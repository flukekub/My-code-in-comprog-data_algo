#include<bits/stdc++.h>
using namespace std ;

bool checkvirus( int left , int right , vector<int> v   ){
    if( right - left == 1 ){
        if( v[left] == 0 && v[right] == 1 ){
            return true ;
        }
        else{
            return false ;
        }
        
    }


    int mid = (left+right)/2 ;
    vector<int> rev ;
    for( int i = left ; i <= mid ;i++)rev.push_back( v[i]);

    reverse( rev.begin(),rev.end());
    return (checkvirus( left , mid , v ) || checkvirus(0 , rev.end()-1-rev.begin() , rev )) && checkvirus( mid+1,right,v) ;
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
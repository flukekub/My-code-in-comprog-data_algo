#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
   vector<int> v ;
   int e ;
   while( cin >> e ){
        if( find(  v.begin(), v.end() , e ) == v.end())
        v.push_back(e);
   }
   sort(v.begin(),v.end());
   cout << v.size()<< endl;
    int end = v.size();
   if( v.size() > 10 ){
    end = 10 ;
   }
   for( int i = 0 ; i < end ;i++){
    cout << v[i]<< ' ';
   }
    
}
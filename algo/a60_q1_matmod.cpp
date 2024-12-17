#include<bits/stdc++.h>
using namespace std;

vector<int> matrix_multiply(const vector<int> &M,const vector<int> &N,int k){
    vector<int> v(4) ;
    v[0] = (M[0]*N[0] + M[1]*N[2])%k ;
    v[1] = (M[0]*N[1] + M[1]*N[3])%k ;
    v[2] = (M[2]*N[0] + M[3]*N[2])%k ;
    v[3] = (M[2]*N[1] + M[3]*N[3])%k ;
    return v ;
}
vector<int> sol ( int n , int k , map<int,vector<int>> & mem ){
    if( n == 1 )return mem[1];
    if( mem.find(n) ==  mem.end()){
        if( n % 2 == 0 ){
            vector<int> mat1 = sol( n/2 , k , mem);
            mem[n] = matrix_multiply(mat1,mat1,k); 
        }else{
            vector<int> mat1 = sol( n/2 , k , mem );
            vector<int> mat2 = sol( (n+1)/2 , k , mem );
            mem[n] = matrix_multiply( mat1,mat2,k);
        }
    }
    return mem[n] ;
}


int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> m(4) ;
    cin >> m[0] >> m[1] >> m[2] >> m[3] ;
    map<int,vector<int>> mem ;
    mem[1] = m ;
    for( auto e : sol( n,k,mem)){
        cout << e << " " ;
    }
}
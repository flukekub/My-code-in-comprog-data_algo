#include<bits/stdc++.h>
using namespace std ;






void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right) {
    if( a == 0 ){
       v[top].push_back(b);
       return ;
    }

    int mlf = (left + right+1)/2;
    int mtb = (top + bottom+1 )/2 ;

    recur( v , a-1,b , top , mtb , left , mlf);
    recur( v , a-1 ,b-1,top ,mtb, mlf, right );
    recur( v , a-1,b+1, mtb , bottom , left , mlf);
    recur( v , a-1 ,b, mtb,bottom, mlf, right );

}



int main(){
    int a,b ;
    cin >> a >> b ;
    
    
    
   vector<vector<int>> v( 1<< a ) ;
    
    
    recur( v ,a,b, 0 ,(1 << a) -1 ,0 ,(1 << a) -1) ;

    for( auto e : v ){
        for( auto c : e ){
            cout << c << " ";
        }
        cout << "\n";
    }
}
#include<bits/stdc++.h>
using namespace std ;
int r , c ;

void solve(  vector<vector<int>> &v , int at_r, int at_c  ,vector<vector<int>> &visit , string s  ){
    
   if( at_r > r - 1 ||at_c > c - 1 || at_r < 0 || at_c < 0 ||visit[at_r][at_c] == 1 || v[at_r][at_c] == 1 ){
        return ;
   }
  
   if( at_r == r - 1 && at_c == c - 1 ){
        cout << s << "\n";
        
        return ;
   }
    visit[at_r][at_c] = 1 ;
    
    solve( v , at_r,at_c+1,visit,s+ "A") ;
    solve( v , at_r+1,at_c,visit,s+ "B");
    solve( v , at_r-1,at_c,visit,s+ "C") ;
    
    visit[at_r][at_c] = 0 ;

    
}

int main(){
    
    cin >> r >> c ;
    vector<int>temp(r+100,0);
    vector<vector<int>> v(c+100,temp) ;
    vector<vector<int>> visit = v ;
    for( int i = 0 ; i < r ; i++){
        for( int j = 0 ; j < c ; j++){
            cin >> v[i][j];
        }
    }
    string s = "";
    solve( v , 0, 0 ,visit,s );
    cout << "DONE";
}
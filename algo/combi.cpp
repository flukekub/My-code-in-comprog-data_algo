#include<bits/stdc++.h>
using namespace std ;
set<pair<int,int>> con ;



void perm(int n,vector<int> &sol,int len,vector<bool> &used) {
   
    if (len < n) {
        for( auto e : con ){
            if( used[e.first] == false && used[e.second]== true)
            return;
        }
        for (int i = 0;i<n;i++) {
            if (used[i] == false) {
                used[i] = true;
                sol[len] = i;

                
                perm(n,sol,len+1,used);
                used[i] = false;
            }
        }
    } else {
    for (auto &x : sol) cout << x << " ";
        cout << endl;
    }
}



int main(){
    int n ,m;
    cin >> n >> m;
    
    while( m-- ){
        int x ,y;
        cin >> x  >> y ;
        con.insert(make_pair(x,y));
    }
    vector<int> sol(n,0);
    vector<bool> used(n,false);
    perm( n, sol,0,used);
}
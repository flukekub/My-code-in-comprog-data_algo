#include<bits/stdc++.h>
using namespace std ;

void combi(int n,vector<int> &sol,int len,int tid ) {
    if (len < n) {
        sol[len] = 0;
        combi(n,sol,len+1,tid);
        sol[len] = 1;
        combi(n,sol,len+1,tid);
    } else {
        bool repeat =false ;
        for (int i = 0 ;i < sol.size() -tid+1 ; i++){
            
            if( sol[i] == 0 ){
                continue;
            }
            int count = 0 ;
            for( int j = i ,k = 0 ; k < tid+1 ; k++ ,j++){
                if( count == tid ){
                    repeat = true ; 
                    break;
                }
                if( sol[j] == 1  ){
                    count++;
                   
                }else{
                    count =  0 ;
                }
            }
           if( repeat  )break;
            
        }
        if( repeat ){
            for( int i = 0 ; i < sol.size() ;i++ ){
                cout << sol[i];
            }
            cout << "\n";
        }
    }
}


int main(){
    int n , tid ;
    cin >> n >> tid ;

    vector<int> sol(n);
    combi(n,sol,0,tid);
}
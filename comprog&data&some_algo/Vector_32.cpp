#include<bits/stdc++.h>
using namespace std;


int sum_vec( vector<int> k ){
    int sum = 0 ;
    for(auto e : k){
        sum += e ;
    }
    return sum ;
}
vector<vector<int>> first_fit(vector<int> d ){
    vector<vector<int>> bins ;
    for(auto & e : d){
        bool add = false;
        for( int i = 0 ; i < bins.size() ; i++ ){
            if( sum_vec(bins[i]) + e <= 100 ){
                bins[i].push_back(e);
                add = true ;
                break;
            }
        }
        if( !add )
        bins.push_back({e});
    }
    return bins ;
}
vector<vector<int>> best_fit(vector<int> d ){
    vector<vector<int>> bins ;
    for(auto & e : d){

        int max = 0 ;
        int index = -999 ;
        for( int i = 0 ; i < bins.size() ; i++ ){
            if( sum_vec(bins[i]) +e > max && sum_vec(bins[i]) +e  <= 100){
                max =  sum_vec(bins[i]) +e ;
                index = i ;
            }
        }
        if( index == -999 ){
            bins.push_back({e});    
        }else{
            bins[index].push_back(e);  
        }
        
    }
    return bins ;
}


void output( vector<vector<int>> k ){
   vector<tuple<int,int,vector<int>>> x ;
   for( auto & e : k ){
        sort(e.begin(),e.end());
        x.push_back({100 - sum_vec(e),e.size(),e });
   }
    sort(x.begin(),x.end());
   for( auto e : x ){
    for( auto c : get<2>(e) ){
        cout << c << " ";
    }
    cout << "\n";
   }
   
}


int main(){
    string cmd ;
    int n ;
    cin >> cmd ;
    vector<int> d ;
    while( cin >> n){
        d.push_back(n);
    }
    vector<vector<int>> bins ;
    if( cmd == "first"){
        output(first_fit(d));
    }else{
        output(best_fit(d));
    }
}




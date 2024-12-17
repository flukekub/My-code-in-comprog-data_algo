#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;
int main(){
    int e ;
    vector< tuple<int,int,int> > v ;
    vector<int> d ;
  

    while (cin >> e ){
        d.push_back(e);
    }
    
    for( int i =0 ,j=0; i < d.size();i++){
        if( i != 0 ){
            if( d[i-1] != d[i]){
                v.push_back(make_tuple(d[i],i,i+1 ));
                j++;
            }else{
                get<2>(v[j-1])++;
            }
                

        }else{
            v.push_back(make_tuple(d[i],i,i+1 ));
            j++;
        }
    }
    int most = get<2>(v[0])- get<1>(v[0]);
    for( int i = 1 ; i < v.size();i++){
        if( get<2>(v[i])- get<1>(v[i]) > most){
            most = get<2>(v[i])- get<1>(v[i]) ;
        }
    }
    vector< tuple<int,int,int> > nv ;
    for( int i = 0 ; i < v.size();i++){
        if( get<2>(v[i]) - get<1>(v[i]) == most){
            nv.push_back( v[i]) ;
        }
    }
    sort( nv.begin(),nv.end());

    for( int i = 0 ;i < nv.size();i++){
        cout << get<0>(nv[i]) << " --> x[ "<< get<1>(nv[i]) << " : "<< get<2>(nv[i])<<" ]"<< endl;
    }

}
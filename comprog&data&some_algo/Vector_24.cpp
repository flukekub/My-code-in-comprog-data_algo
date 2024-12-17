#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string sinka;
    double raka ;
    vector< pair<string,double> > v ;
    while( cin >> sinka){
        if(sinka == "END"){
            break;
        }
        cin >> raka;
        pair<string,double>  p = {sinka,raka};
        v.push_back(p);

    }
    string check ;
    int a[v.size()] = {0} ;
    while( cin >> check){
        for( int i = 0 ; i < v.size() ; i++ ){
            if( v[i].first == check){
                a[i] += 1;
            }
        }
    }
    for(int i = 0 ; i < v.size() ; i++){
        v[i].second *= a[i];
    }
    vector< pair<double,string> > nv  ;

    for(int i = 0 ; i < v.size() ; i++){
        nv.push_back( make_pair( -v[i].second , v[i].first) );
    }

    sort( nv.begin(), nv.end());
    int end = nv.size();
    if( v.size() > 3){
        end = 3 ;
    }

    bool allzero = true ;
    for( int i = 0   ; i < end ; i++ ){
        if( nv[i].first != 0){
            allzero = false;
        }
        
    }
    if ( allzero){
        cout << "No Sales";
        return 0 ;
    }

    for( int i = 0   ; i < end ; i++ ){
        if( nv[i].first != 0)
        cout << nv[i].second << " " << -nv[i].first << endl ; 
    }
}
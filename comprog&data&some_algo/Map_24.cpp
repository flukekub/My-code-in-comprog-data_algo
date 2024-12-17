#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,double> m ,mtotal;
    int n ;
    cin >> n ;
    while(n--){
        string nameice ;
        double price ;
        cin >> nameice >> price ;
        m[nameice] = price ;
        mtotal[nameice] = 0 ;
    }
    
    int k  ;
    double total = 0;
    cin >> k ; 
    while( k-- ){
        string name ;
        double jumnuan ;
        cin >> name >> jumnuan;
        
        if( mtotal.find(name) != m.end()){
            total += m[name] * jumnuan ;
            mtotal[name] +=  m[name] * jumnuan ;
        }

    }
    vector<pair<double,string>> v ;
    for( auto e : mtotal){
       v.push_back(make_pair(-e.second,e.first));
    }
    sort( v.begin(),v.end() );
    if( total != 0 ){
        cout << "Total ice cream sales: "<< total << "\n" << "Top sales: ";
        cout << v[0].second << " " ;
        int i = 0 ;
        while(v[i].first == v[i+1].first ){
            cout << v[i+1].second<<" ";
            i++;
        }
        
    }else{
        cout << "No ice cream sales";
    }
    

}
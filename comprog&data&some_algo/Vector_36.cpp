#include<bits/stdc++.h>
using namespace std ;

string chenge_grade( tuple<int,string,string> f ,char c ){
    string a[] = {"F","D","D+","C","C+","B","B+","A","A" };

    for(int i =0 ; i < 9 ; i++  ){
        if( get<2>(f) == a[i] && c == '+'){
            get<2>(f) = a[i+1];
            break;
        }
        if( get<2>(f) == a[i] && c == '-' && get<2>(f) != "F" ){
            get<2>(f) = a[i-1] ;
            break;
        }else if( get<2>(f) == a[i] && c == '-' && get<2>(f) == "F"){
            get<2>(f) = "F" ;
            break;
        }
    }
    return get<2>(f) ;
}


int main(){
    int n ;
    cin >> n;
    int k = 0 ;
    vector<tuple<int,string,string>> v ;
    while( n-- ){
        string name ;
        string grade ;
        cin >> name >> grade ;

        v.push_back(make_tuple(k,name,grade));
        k++;
    }
    string cmd ;
    while( cin >> cmd ){
        for( auto & e : v ){
            if( cmd.substr(0,cmd.length()-1) == get<1>(e) ){
               get<2>(e) =  chenge_grade( e ,cmd[cmd.length()-1]);
            }
        }
        
    }
    vector<tuple<int,int,string,string>> n_v ;
    
    for( auto & e : v ){
        int prior = 999 ;
        if( get<2>(e) == "A" ){
            prior = 1 ;
            n_v.push_back(make_tuple( prior,get<0>(e),get<1>(e),get<2>(e)));
        }else if( get<2>(e) == "B+" ){
            prior = 2 ;
             n_v.push_back(make_tuple( prior,get<0>(e),get<1>(e),get<2>(e)));
        }else if( get<2>(e) == "B" ){
            prior = 3 ;
             n_v.push_back(make_tuple( prior,get<0>(e),get<1>(e),get<2>(e)));
        }else if( get<2>(e) == "C+" ){
            prior = 4 ;
             n_v.push_back(make_tuple( prior,get<0>(e),get<1>(e),get<2>(e)));
        }else if( get<2>(e) == "C" ){
            prior = 5 ;
             n_v.push_back(make_tuple( prior,get<0>(e),get<1>(e),get<2>(e)));
        }else if( get<2>(e) == "D+" ){
            prior = 6 ;
             n_v.push_back(make_tuple( prior,get<0>(e),get<1>(e),get<2>(e)));
        }else if( get<2>(e) == "D" ){
            prior = 7 ;
             n_v.push_back(make_tuple( prior,get<0>(e),get<1>(e),get<2>(e)));
        }else if( get<2>(e) == "F" ){
            prior = 8 ;
             n_v.push_back(make_tuple( prior,get<0>(e),get<1>(e),get<2>(e)));
        }
    }

    sort(n_v.begin(),n_v.end());

    for( auto e : n_v){
        cout << get<2>(e) << " " << get<3>(e) << "\n";
    }
}
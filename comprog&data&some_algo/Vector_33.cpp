#include<bits/stdc++.h>
using namespace std;

double total_score(vector<pair<string,double>> v){
    double total = 0 ;
    for(auto e : v){
        total += e.second ;     
    }
    return total;
}
int sum_khon( vector<tuple< double,int,pair<string,double> >> khon ){
    int total = 0 ;
    for( tuple e : khon){
        total +=  get<1>(e);
    }
    return total ;
}
int main(){

    string namepak ;
    vector<pair<string,double>> d;
    while(cin >> namepak){
        if( namepak == "END"){
            break;
        }
        double score ;
        cin >> score;
        
        d.push_back(make_pair(namepak,score));
    }
    double total = total_score(d) ,totalper100 = total_score(d)/100 ;
    vector<tuple< double,int,pair<string,double> >> khon ;
    for( pair e :d ){
        double x , z;
        int y ;

        x = e.second/totalper100 ;
        y = e.second/totalper100 ;
        z = x - y ;
        khon.push_back(make_tuple(-z,y,e));
    }
    int totalkhon = sum_khon(khon);
    if( totalkhon <= 100 ){
        int dif = 100 -totalkhon ;
        sort(khon.begin(),khon.end());
        for( int i = 0 ; i < dif ;i++){
            get<1>(khon[i]) =  get<1>(khon[i]) + 1 ;
        }
    }

    vector<tuple<int,double,string>> answer ;
    for(tuple e : khon ){
        string name ;
        int people ;
        double kanan ;
        pair<string,double> xxx ;
        xxx = get<2>(e);
        
        name = xxx.first ;
        people = get<1>(e);
        kanan = xxx.second;
        answer.push_back(make_tuple( -people ,-kanan, name ));
    }

    sort(answer.begin(),answer.end());
    vector<tuple<string,int,double>> new_answer;
    for( auto e : answer ){
        string name ;
        int people ;
        double kanan ;

        name = get<2>(e) ;
        people = -get<0>(e);
        kanan = -get<1>(e);
        if(people != 0 )
            new_answer.push_back(make_tuple(name,people,kanan));
    }
    for( auto e : new_answer){
        cout << get<0>(e)<< " " << get<1>(e)<< " " << get<2>(e) << "\n"; 
    }

}
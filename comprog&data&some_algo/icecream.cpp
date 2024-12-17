#include<bits/stdc++.h>
using namespace std ;




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n , m , start ;
    cin >> n >> m >> start ;
    int a , s ;
    map <int,int> ch_money ;
    while ( n-- ){
        cin >> a >> s ;
        ch_money[a] = s ;
    }
    vector<int> v ;
    int money_per_day  = start;
    int total_money =  0; 
    int price_parabola , day_hoax ;
    for( int i = 0 ; i <= 100000 ; i++ ){
            //เปลี่ยนเงินที่เก็บในวันที่  i
            if( ch_money.find(i) != ch_money.end()){
                money_per_day = ch_money[i];
            }
            total_money += money_per_day ; 
            v.push_back( total_money );
    }
    while( m-- ){
        cin >> price_parabola >> day_hoax ;
        int day_want = lower_bound( v.begin() , v.end() , price_parabola) - v.begin() ;
        if( day_want <= day_hoax) {
            cout << day_want  << ' '  ;
            continue;
        }
        cout << lower_bound( v.begin() , v.end() , price_parabola + v[day_hoax]) - v.begin()<< " " ;
    }
}
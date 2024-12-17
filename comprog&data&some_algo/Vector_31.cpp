#include<bits/stdc++.h>
using namespace std ;


void show( vector<string>  v ){
    string answer ;
    for( auto  e :v ){
        if( e != "N*")
        answer += e + ", ";
    }
    cout << answer.substr(0 , answer.length() - 2);
    cout << "\n";
}
bool issubset( vector<string> v1 , vector<string> v2 ){
    for( auto e : v1){
        if( find( v2.begin(), v2.end(), e ) == v2.end() ){
            return false ;
        }
    }
    return true ;
}

int main(){
    char BINGO[5] ;
    for(int i = 0 ; i < 5 ; i++){
        cin >> BINGO[i];
    }
    vector< vector<string> > bingo ;
    for(int i = 0 ; i < 5 ;i++){
        vector<string> in ;
        string t ;
        for( int j = 0 ; j < 5 ; j++){
            cin >> t ;
            in.push_back( BINGO[j] + t );
        }
        bingo.push_back( in );
    }
    for( int j = 0 ; j < 5 ; j++ ){
        vector<string> in ;
        for(int i = 0 ; i < 5 ; i++ ){
            in.push_back( bingo[i][j]);
        }
        bingo.push_back( in );
    }
    vector<string> inn ;
    for(int i = 0 ; i < 5 ;i++){
        inn.push_back( bingo[i][i]);
    }
    bingo.push_back(inn);

    vector<string> innn ;
    for(int i = 0 ; i < 5 ;i++){
        innn.push_back( bingo[4-i][i]);
    }
    bingo.push_back(innn);

    

    string check ;
    vector<string> card;
    card.push_back( "N*");
    int n= 0 ;
    bool isbingo = false ;
    while( cin >> check){    
        card.push_back(check);
        n++ ;
        for( auto b : bingo){
            if( issubset( b, card) ){
                if( !isbingo ){
                    cout << n << "\n";
                }
                show( b ) ;
                isbingo = true;
            }
        }

        if( isbingo){
            break;
        }
    }
    
    
    //cout << "dadasd";


    
}
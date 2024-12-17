#include<bits/stdc++.h>
using namespace std;
int main(){
    char array[4][6];
    for( int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 6 ;j++ ){
            array[i][j] = '0' ;
        }
    }
    array[0][0] = ' '; array[1][0] = ' ' ; array[0][2] = ' ';array[0][4] = ' ';
    string time ;
    cin >> time ;
    string hour = time.substr(0,2);
    string minute = time.substr(3,2);
    string sec = time.substr(6,2);

    if( hour[0] == '1' ){
        array[3][0] = '1' ;
    }else if ( hour[0] == '2'){
        array[2][0] = '1' ;
    }
    
    if( hour[1] == '1' ){
        array[3][1] = '1' ;
    }else if ( hour[1] == '2'){
        array[2][1] = '1' ;
    }else if ( hour[1] == '3'){
        array[2][1] = '1' ;
        array[3][1] = '1' ;
    }else if ( hour[1] == '4'){
        array[1][1] = '1' ;
    }else if ( hour[1] == '5'){
        array[1][1] = '1' ;
        array[3][1] = '1' ;
    }else if ( hour[1] == '6'){
        array[1][1] = '1' ;
        array[2][1] = '1' ;
    }else if ( hour[1] =='7'){
        array[1][1] = '1' ;
        array[2][1] = '1' ;
        array[3][1] = '1' ;
    }else if ( hour[1] == '8'){
        array[0][1] = '1' ;
    }else if ( hour[1] == '9'){
        array[0][1] = '1' ;
        array[3][1] = '1' ;
    }


    if( minute[0] =='1' ){
        array[3][2] = '1' ;
    }else if ( minute[0] == '2'){
        array[2][2] = '1' ;
    }else if ( minute[0] =='3'){
        array[2][2] = '1' ;
        array[3][2] = '1' ;
    }else if ( minute[0] == '4'){
        array[1][2] = '1' ;
    }else if ( minute[0] == '5'){
        array[1][2] = '1' ;
        array[3][2] = '1' ;
    }else if ( minute[0] =='6'){
        array[1][2] = '1' ;
        array[2][2] = '1' ;
    }

    if( minute[1] == '1' ){
        array[3][3] = '1' ;
    }else if ( minute[1] == '2'){
        array[2][3] = '1' ;
    }else if ( minute[1] == '3'){
        array[2][3] = '1' ;
        array[3][3] = '1' ;
    }else if ( minute[1] == '4'){
        array[1][3] = '1' ;
    }else if ( minute[1]=='5'){
        array[1][3] = '1' ;
        array[3][3] = '1' ;
    }else if ( minute[1] == '6'){
        array[1][3] = '1' ;
        array[2][3] = '1' ;
    }else if ( minute[1] == '7'){
        array[1][3] = '1' ;
        array[2][3] = '1' ;
        array[3][3] = '1' ;
    }else if ( minute[1] == '8'){
        array[0][3] = '1' ;
    }else if ( minute[1] == '9'){
        array[0][3] = '1' ;
        array[3][3] = '1' ;
    }

    if( sec[0] == '1' ){
        array[3][4] = '1' ;
    }else if ( sec[0] == '2'){
        array[2][4] = '1' ;
    }else if ( sec[0] == '3'){
        array[2][4] = '1' ;
        array[3][4] = '1' ;
    }else if ( sec[0] == '4'){
        array[1][4] = '1' ;
    }else if ( sec[0] == '5'){
        array[1][4] = '1' ;
        array[3][4] = '1' ;
    }else if ( sec[0] == '6'){
        array[1][4] = '1' ;
        array[2][4] = '1' ;
    }

    if( sec[1] == '1' ){
        array[3][5] = '1' ;
    }else if ( sec[1] == '2'){
        array[2][5] = '1' ;
    }else if ( sec[1] == '3'){
        array[2][5] = '1' ;
        array[3][5] = '1' ;
    }else if ( sec[1] == '4'){
        array[1][5] = '1' ;
    }else if ( sec[1]=='5'){
        array[1][5] = '1' ;
        array[3][5] = '1' ;
    }else if ( sec[1] == '6'){
        array[1][5] = '1' ;
        array[2][5] = '1' ;
    }else if ( sec[1] == '7'){
        array[1][5] = '1' ;
        array[2][5] = '1' ;
        array[3][5] = '1' ;
    }else if ( sec[1] == '8'){
        array[0][5] = '1' ;
    }else if ( sec[1] == '9'){
        array[0][5] = '1' ;
        array[3][5] = '1' ;
    }
    for( int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 6 ;j++ ){
            cout << array[i][j] ; 
        }
        cout << '\n';
    }
}
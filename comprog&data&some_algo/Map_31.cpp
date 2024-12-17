#include<bits/stdc++.h>
using namespace std ;

vector<pair<string,string>> select( vector<tuple<double ,string , vector<string>>> student , map<string,int> pak_visha ){
    vector<pair<string,string>> selected_student ;
    for( tuple e : student){
        pair<string,string> student_choose ;
        for( auto c :  get<2>(e)){
            if( pak_visha[c] > 0){
                student_choose = make_pair( get<1>(e) , c) ;
                pak_visha[c] -= 1 ;
                break;
            }
        }
        selected_student.push_back(student_choose);
    }

    return selected_student ;

}




int main(){
    int n ;
    cin >> n ;
    map<string,int> pak_visha ;
    while( n-- ){
        string pak ; 
        int jumnuan_khon ;
        cin >> pak >> jumnuan_khon;
        pak_visha[pak] = jumnuan_khon ;
    }
    int k ;
    cin >> k ;
    vector<tuple<double ,string , vector<string>>> student ;
    while(k--){
        vector<string> sonjai ;
        string ID ;
        double score ;
        string  pak;

        cin >> ID >> score ;
        int rob = 4 ;
        while( rob--){
            cin >> pak;
            sonjai.push_back(pak);
        }
        student.push_back(make_tuple (-score,ID,sonjai));
    }
    sort(student.begin(),student.end());
    vector<pair<string,string>> selected_student  = select(student,pak_visha) ;
    sort(selected_student.begin(),selected_student.end());

    for( auto e : selected_student){
        cout << e.first << " " << e.second << "\n";
    }
}

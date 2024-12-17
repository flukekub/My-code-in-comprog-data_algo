#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> s ;

void solve(  ){
    auto left = s.begin();
    auto right = s.begin();
    right++ ;
    int l  = (*left).first ;
    int r = ( *left).second ; 
    
    while( right != s.end()){
        if( (*left).second  >=  (*right).first  &&  (*left).second  >= (*right).second  ){
            l = ( *left ).first ;
            r = ( *left ).second ;
            if( s.size() > 3 ){
                right = s.erase( right );
                s.erase(left);
                s.insert( make_pair(l,r));
                
            }else if( s.size() == 3 ) { 
                right = s.erase( right );
                s.erase(left);
                s.insert( make_pair(l,r));
                
                
            }else if( s.size( ) == 2 ){
                s.erase( right );
                s.erase(left);
                s.insert( make_pair(l,r) );
                break;
            }
        }else if( (*left).second  >=  (*right).first &&  (*left).second  <= (*right).second ){
            l = ( *left ).first ;
            r = ( *right ).second ;
            if( s.size() > 3 ){
                right = s.erase( right );
                s.erase(left);
                s.insert( make_pair(l,r));
                
            }else if( s.size() == 3 ) { 
                right = s.erase( right );
                s.erase(left);
                s.insert( make_pair(l,r));
                
                
            }else if( s.size( ) == 2 ){
                s.erase( right );
                s.erase(left);
                s.insert( make_pair(l,r) );
                break;
            }
        }else{
            right++ ;
            left++ ;
        }
            
    }

}

int main(){
    
    /*s.insert( make_pair( 5,10 ));
    s.insert( make_pair( 15,20 ));
    s.insert( make_pair( 25,30 ));
    s.insert( make_pair( 35,40 ));
    s.insert( make_pair( 24,50 ));
    solve( );*/
    int n ;
    cin >> n ;
    for( int i = 0 ; i < n ; i++ ){
        int cmd ;
        cin >> cmd ;
        if( cmd == 1 ){
            int first , second ;
            cin >> first >> second ;
            s.insert( make_pair( first,second ));
            //cout << s.size() << "\n";
            solve( );
            /*for( auto e : s ){
                cout <<" "<< e.first<<":"<<e.second << " ";
            }
            cout << "nub "<<"\n";*/
            
        }else if( cmd == 2 ) {
            int set = s.size();
            cout << set << "\n";
        }
    }
}
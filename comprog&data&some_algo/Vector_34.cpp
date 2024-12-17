#include<bits/stdc++.h>
using namespace std;

double avg(vector<int> v ){
    double avg,total=0;
    int divided = v.size();

    for( auto e : v ){
        total += e ;
    }
    avg = total/divided ;

    return  round(avg*100.0)/100.0 ;
}

int main(){
    int n ;
    cin >> n ;
    n=n-1;
    string reset;
    cin >> reset ;
    int set ,countnew=0,countorder=0,countnext = 0;
    cin >> set ;
    vector<int> time ;
    vector<int> set_count ;
    vector<int> qtime ; 

    while(n--){
        string cmd ;
        cin>> cmd;
        if( cmd == "next"){
            cout << ">> call " << set_count[countnext] << "\n" ;
            
            while(cin >> cmd ){
                if( cmd == "next"){
                    cout << ">> call " << set_count[++countnext] << "\n" ;
                    
                }else if(cmd == "order"){
                    int finish_t ;
                    cin >> finish_t;
                    cout << ">> qtime " << set_count[countnext] << " " << finish_t - time[countnext]<< "\n";
                    qtime.push_back(finish_t - time[countnext]);
                    countnext++;
                    break;
                }else{
                    countnext++;
                    break;
                }
                
            }
            
        }
        if( cmd == "new" ){
            int t ;
            cin >> t ;
            time.push_back(t);
            cout << ">> ticket " << set + countnew <<"\n" ;
            set_count.push_back(set+countnew);
            countnew++;

        }
        
        
        if( cmd == "avg_qtime"){
            cout << ">> avg_qtime " << avg(qtime)<< "\n";
        }

        
    }

}
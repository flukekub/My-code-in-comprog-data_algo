#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<int> v ;
    for(int i = 0 ; i < n ; i++ ){
        int num ;
        cin >> num ;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int give ;
    while( cin >> give ){
        int up = give + k ;
        int down = give -k;
        
        int end = upper_bound (v.begin(), v.end(), give+k) - v.begin() ;
        int start = lower_bound (v.begin(), v.end(), give-k) - v.begin();

        cout << end - start << " " ;
    }
}
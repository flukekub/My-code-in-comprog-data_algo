#include<bits/stdc++.h>
using namespace std ;
int main(){
  int n ; 
  cin >> n; 
  vector<pair<string,int>> v;
  set<int>overall_score ;
  while( n-- ){
    string name ;
    int score ;
    cin >> name >> score ;
    overall_score.insert(score);
    bool found = false;
    int i =0;
    for(  i = 0 ; i < v.size() ; i++ ){
      if( v[i].first == name ){
        found = true ;
        break;
      }
    }
    if( found ){
      if ( v[i].second < score ){
        v[i].second = score ;
      }
    }else{
      v.push_back(make_pair(name,score));
    }
  }
  vector<pair<int,string>> answer;
  for( auto e : v ){
    answer.push_back(make_pair(-e.second,e.first));
  }

  sort(answer.begin(),answer.end());
  int rob ; 
  cin >> rob ;
  if( overall_score.size() < rob ){
    rob = overall_score.size();
  }
  for(int i = 0 ; i < rob ; i++){
    cout << -answer[i].first << " " << answer[i].second << " "; 
    
    while( answer[i+1].first == answer[i].first && i +1 < answer.size()){
      cout << answer[i+1] .second << " " ;
      i++ ;
    }
    
    cout << "\n" ;
  }
  
}
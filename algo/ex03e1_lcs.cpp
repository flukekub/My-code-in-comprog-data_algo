#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    
    int m = A.size();
    int n = B.size();
    
    // สร้างตาราง DP ขนาด (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // เติมตาราง DP
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                //cout << i << " " << j <<"\n";
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                //cout << i << " " << j<< "\n" ;
            }
        }
    }
    
    // คำตอบคือ dp[m][n]
    for( int i = 0;  i < m ; i++){
        for( int j = 0 ;  j< n ; j++){
            cout << dp[i][j] <<" ";
        }
        cout << "\n";
    }
    cout << dp[m][n] << endl;
    
    return 0;
}

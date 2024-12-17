#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; // Replace 1e9 with INT_MAX for clarity
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

void bfs(int R, int C, vector<vector<int>>& arr, int& sum) {
    vector<vector<int>> dist(R, vector<int>(C, INF));
    vector<vector<bool>> visit(R, vector<bool>(C, false));
    
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (visit[x][y]) continue; // Skip already visited nodes
        visit[x][y] = true;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < R && ny < C && arr[nx][ny] != 0) {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    if (arr[nx][ny] == 2) {
                        sum += dist[nx][ny] * 2;
                        // arr[nx][ny] = 1; // Mark as visited
                    }
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    int R, C;
    cin >> R >> C;
    
    vector<vector<int>> arr(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    
    int sum = 0;
    bfs(R, C, arr, sum);
    
    cout << sum << endl;
    return 0;
}

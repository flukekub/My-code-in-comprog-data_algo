#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void findPaths(int r, int c, int R, int C, const vector<vector<int>>& grid, vector<vector<bool>>& visited, string path, set<string>& results) {
    // หากถึงเป้าหมาย ให้เพิ่ม path ลงในผลลัพธ์
    if (r == R && c == C) {
        results.insert(path);
        return;
    }

    // Mark current cell as visited
    visited[r][c] = true;

    // Move Right (A)
    if (c + 1 <= C && !visited[r][c + 1] && grid[r][c + 1] == 0) {
        findPaths(r, c + 1, R, C, grid, visited, path + "A", results);
    }

    // Move Down (B)
    if (r + 1 <= R && !visited[r + 1][c] && grid[r + 1][c] == 0) {
        findPaths(r + 1, c, R, C, grid, visited, path + "B", results);
    }

    // Move Up (C)
    if (r - 1 >= 1 && !visited[r - 1][c] && grid[r - 1][c] == 0) {
        findPaths(r - 1, c, R, C, grid, visited, path + "C", results);
    }

    // Backtrack: Unmark current cell
    visited[r][c] = false;
}
int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R + 1, vector<int>(C + 1)); // ตารางขนาด R * C
    vector<vector<bool>> visited(R + 1, vector<bool>(C + 1, false)); // ตารางเก็บสถานะ visited

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> grid[i][j];
        }
    }

    set<string> results; // ใช้ set เพื่อเก็บคำตอบที่ไม่ซ้ำกัน

    // เริ่มต้นการค้นหาเส้นทางจาก (1, 1)
    findPaths(1, 1, R, C, grid, visited, "", results);

    // แสดงผลลัพธ์
    for (const auto& path : results) {
        cout << path << endl;
    }
    cout << "DONE" << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> warp_map;
set<vector<int>> unique_paths; // ใช้เก็บเส้นทางที่ไม่ซ้ำ

void findPaths(int current, int b, vector<int> &path) {
    if (current == b) {
        unique_paths.insert(path); // ถ้าถึงห้อง b แล้วให้เพิ่มเส้นทางลงใน set
        return;
    }
    for (int next : warp_map[current]) {
        path.push_back(next); // เพิ่มห้องถัดไปในเส้นทาง
        findPaths(next, b, path); // เรียกหาเส้นทางต่อไป
        path.pop_back(); // เอาห้องสุดท้ายออกเพื่อย้อนกลับ
    }
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        warp_map[x].push_back(y); // บันทึกจุดวาร์ป x -> y
    }

    vector<int> path = {a}; // เส้นทางเริ่มต้นจากห้อง a
    findPaths(a, b, path);  // หาเส้นทางทั้งหมดจากห้อง a ไป b

    if (unique_paths.empty()) {
        cout << "no" << endl; // ถ้าไม่มีเส้นทางเลย
    } else {
        for (const auto &p : unique_paths) {
            for (size_t i = 0; i < p.size(); i++) {
                cout << p[i];
                if (i < p.size() - 1) cout << " -> ";
            }
            cout << endl;
        }
    }

    return 0;
}

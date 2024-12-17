#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> start(N), finish(N);

    for (int i = 0; i < N; i++) cin >> start[i];
    for (int i = 0; i < N; i++) cin >> finish[i];

    // สร้างคู่ข้อมูล (finish[i], start[i]) และจัดเรียงตาม finish[i]
    vector<pair<int, int>> classes(N);
    for (int i = 0; i < N; i++) {
        classes[i] = {finish[i], start[i]};
    }
    sort(classes.begin(), classes.end());

    // Greedy Algorithm
    int count = 0, lastFinishTime = 0;
    for (auto &cls : classes) {
        if (cls.second >= lastFinishTime) {  // start >= lastFinishTime
            count++;
            lastFinishTime = cls.first;  // อัปเดตเวลาสิ้นสุด
        }
    }

    cout << count << endl;

    return 0;
}

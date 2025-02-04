#include <iostream>
#include <queue>
using namespace std;

int main() {
    long long int n, m;
    while (cin >> n >> m) {
        if (m <= 1 || n <= 1 || n < m) { // 修正邏輯條件
            cout << "Boring!" << endl;
            continue;
        }
        
        queue<long long> q;
        q.push(n);
        bool isBoring = false;
        while (n != 1) {
            if (n % m != 0) {
                isBoring = true;
                break;
            }
            n /= m;
            q.push(n);
        }
        if (isBoring || q.back() != 1) { // 檢查隊列的最後一個元素是否為1
            cout << "Boring!" << endl;
        } else {
            bool first = true;
            while (!q.empty()) {
                if (!first) cout << " ";
                cout << q.front();
                q.pop();
                first = false;
            }
            cout << endl;
        }
    }
    return 0;
}

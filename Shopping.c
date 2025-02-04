#include <iostream>
#include<map>

using namespace std;

int main() {
	int n, m;
	while (cin >> n) { //商店數
		map<string, int> mp;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s; //輸入商店名稱
			mp[s] = 0; //輸入價格
		}
		cin >> m; //天數
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int s; //新的價錢
				string p; //輸入商店
				cin >> s >> p;
				mp[p] += s;
			}
			int rank = 0;
			for (auto k : mp) {
				if (k.second > mp["memory"]) {
					rank++;
				}
			}
			cout << rank + 1 << endl;
		}
	}
}
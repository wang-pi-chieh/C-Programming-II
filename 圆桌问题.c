#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m; //n個壞人，n個好人，要殺掉第m個人
	while (cin >> n >> m) {
		vector<int> v(2 * n);//括號內為空間大小
		for (int i = 0; i < 2 * n; i++) {//全部先圍著圓桌坐下並給編號
			v[i] = i;
		}
		int pos = 0;
		while (v.size() > n) { //條件式成立:繼續殺人
			pos = (pos + m - 1) % v.size();//m-1是因為座位是從0開始
			v.erase(v.begin() + pos);
			//因為是圓桌，為了讓他從頭開始算，所以用%
		}
		int cnt = 0;
		int len = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (i == v[cnt] && cnt < v.size()) {
				cout << "G";
				cnt++;
			}
			else {
				cout << "B";
			}
			len++;
			if (len == 50) {//題目規定50個字母為一行
				cout << endl;
				len = 0;
			}
		}
		cout << endl << endl;
	}
}
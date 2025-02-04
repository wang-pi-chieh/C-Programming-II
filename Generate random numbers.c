#include <iostream>
using namespace std;

int main() {
	int num[120] = { 0 };
	int record;
	while (cin >> record) {
		bool flag = false;
		if (record == 0) {
			break;
		}
		num[0] = record;
		int ans;
		for (int i = 0;; i++) {
			num[i + 1] = ((num[i] * num[i]) % 1000000) / 100;
			//cout << num[i + 1] << "D" << endl;
			for (int j = 0; j <= i; j++) {
				if (num[i + 1] == num[j]) {
					flag = true;
					break;
				}
			}
			if (flag) {
				ans = i + 1;
				break;
			}
		}
		cout << ans << endl;
	}

}
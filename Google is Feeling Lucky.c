#include <iostream>
using namespace std;

int main() {
	int T;//case
	cin >> T;
	for (int j = 1; j <= T; j++) {
		string word[10];
		int num[10];
		int max = 0;
		for (int i = 0; i < 10; i++) {
			cin >> word[i] >> num[i];
			if (num[i] > max) {
				max = num[i];
			}
		}
		cout << "Case #" << j << ":" << endl;
			for (int i = 0; i < 10; i++) {
				if (max == num[i]) {
					cout << word[i] << endl;
				}
			}


	}

}
#include <iostream>
using namespace std;

int main() {
	string s;//string不用開陣列?
	string t;

	while (cin >> s >> t) {
		int temp = 0;
		int length = t.length();
		int length_s = s.length()-1;
		int i = 0;
		int word = 0;
		bool flag = true;
		do {
			for (i = temp; i < length; i++) {
 				flag = true;
				if (s[word] == t[i]) {
					flag = false;
					break;
				}
			}
			
			temp = i + 1;
			if (temp > length) {
				flag = true;
			}
			if (flag) {
				cout << "No" << endl;
				break;
			}
			word++;
		} while (length_s--);
		if (!flag) {
			cout << "Yes" << endl;
		}
	}
}
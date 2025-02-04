#include <iostream>

using namespace std;

int main() {
	string word;
	char c;
	while (cin >> word) {
		int num = word.length();
		for (int i = 0; i < num; i++){
			c = word[i] - 7;
			cout << c;
		}
		cout << endl;
	}
}
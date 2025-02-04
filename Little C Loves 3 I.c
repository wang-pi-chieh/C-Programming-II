#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int i = 1;
		while ((n - 1 - i) % 3 == 0) {
			i++;
		}
		cout << "1 " << i << " " << n - 1 - i << endl;
	}
	
}
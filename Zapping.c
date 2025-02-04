#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a == -1 && b == -1) {
			break;
		}
		if (abs(a-b) > 50) {
			cout << 100 - abs(a - b) << endl;
		}
		else {
			cout << abs(a - b) << endl;
		}
	}
}
#include <iostream>
using namespace std;

int main() {
	int t;//case
	cin >> t;
	for (int j = 1; j <= t; j++) {
		
		int n;
		cin >> n;
		int height[50] = { 0 };
		int high = 0;
		int low = 0;
		cin >> height[0];
		for (int i = 1; i < n; i++) {
			cin >> height[i];
			if (height[i - 1] > height[i]) {
				low++;
			}
			else if (height[i - 1] < height[i]) {
				high++;
			}
		}
		cout << "Case " << j << ": ";
		cout << high << " " << low << endl;

	}
}
#include <iostream>
using namespace std;

int main() {
	int g[3], b[3], c[3];
	
	while (cin >> b[0] >> g[0] >> c[0] >> b[1] >> g[1] >> c[1] >> b[2] >> g[2] >> c[2]) {
		int move[6];
		move[0] = b[1] + b[2] + g[0] + g[1] + c[0] + c[2];
		move[1] = b[1] + b[2] + g[0] + g[2] + c[0] + c[1];
		move[2] = b[0] + b[2] + g[0] + g[1] + c[1] + c[2];
		move[3] = b[0] + b[1] + g[0] + g[2] + c[1] + c[2];
		move[4] = b[0] + b[2] + g[1] + g[2] + c[0] + c[1];
		move[5] = b[0] + b[1] + g[1] + g[2] + c[0] + c[2];
		const string s[] = { "BCG","BGC","CBG","CGB","GBC","GCB" };
		int min;
		/*s[0] = "BGC";
		s[1] = "BCG";
		s[2] = "GBC";
		s[3] = "CBG";
		s[4] = "GCB";
		s[5] = "CGB";*/

		/*for (int i = 0; i < 6; i++) {
			cout << move[i] << " ";
		}*/
		min = 0;
		for (int i = 1; i < 6; i++) {
			if (move[min] > move[i]) {
				min = i;
			}
		}
		cout << s[min] << " " << move[min] << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
//果實重量:a-b~a+b
//袋子重量:c-d~c+d

//17~23 7*17=119, 7*23=161, 83~119
//1~21 11*1=11, 11*21=231, 232~236
//2~16 8*2=16, 8*16=128, 128~372

int main() {
	int T;//case
	cin >> T;
	while (T--) {
		int n, a, b, c, d;
		bool flag = true;
		cin >> n >> a >> b >> c >> d;
		int grains[2] = { abs(b - a),a + b };
		int package[2] = { abs(d - c),c + d };
		int weight_start = n * grains[0];
		int weight_end = n * grains[1];
		/*for (int i = 0; i < 2; i++) {
			cout << package[i] << " ";
		}
		cout << "package" << endl;
		for (int i = 0; i < 2; i++) {
			cout << weight[i] << " ";
		}
		cout << "weight" << endl;*/
		if (package[0] > weight_end || package[1] < weight_start) {
			cout << "No" << endl; 
		}else {
			cout << "Yes" << endl;
		}
		/*for (int i = weight_start; i <= weight_end; i++) {
			if (package[1] >= i && i >= package[0]) {
				cout << "Yes" << endl;
				flag = false;
				break;
			}
			
		}*/
	}

}
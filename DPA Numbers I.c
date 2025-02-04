#include <iostream>
using namespace std;

int main(){
	int t;//case
	cin >> t;
	int num;
	while (t--){
		int sum = 0;
		cin >> num;
		int temp = 0;
		for (int i = 1; i < num / 2; i++){
			if (num%i == 0){
				if (temp == i){
					break;
				}
				temp = num / i;
				//cout << i << " i" << endl;
				if (temp == i){
					sum = sum + i;
					break;
				}
				else{
					sum = sum + i + temp;
				}

				//cout << sum << "中間" << endl;
			}
		}
		sum -= num;
		//cout << sum << "結果" << endl;
		if (sum < num){
			cout << "deficient" << endl;
		}
		else if (sum == num){
			cout << "perfect" << endl;
		}
		else if (sum > num){
			cout << "abundant" << endl;
		}
	}
	return 0;
	system("pause");
}
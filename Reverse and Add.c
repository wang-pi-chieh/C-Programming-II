#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int count = 0;
		string num_original;
		bool flag = false;
		cin >> num_original;
		string num_reverse = "ABC";
		int last = num_original.length();
		while (num_original != num_reverse) {
			/*for (int i = 0; i < num_original.length(); i++,last--) {
				num_reverse[i] = num_original[last - 1];
			}*/
			num_reverse = num_original;
			reverse(num_reverse.begin(), num_reverse.end());
			//利用reverse函式，直接反轉數字
			//cout << num_original << " " << num_reverse <<"C" << endl;
			for (int i = 0; i < num_original.length(); i++) {
				if (num_original[i] == num_reverse[i]) {
					continue;
				}
				else {
					count++;
					long long int num1 = stoll(num_original);
					long long int num2 = stoll(num_reverse);
					long long int sum = num1 + num2;
					num_original = to_string(sum);
					//cout << num_original << "C" << endl;
					break;
				}
			}

		}
		cout << count << " " << num_original << endl;

		
	}
}
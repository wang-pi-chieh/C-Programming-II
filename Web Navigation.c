#include <iostream>
#include <stack>
//題目:
//網頁搜尋紀錄
//LIFO，stack的概念
//有兩個stack，一個是forward，另一個是back


using namespace std;

int main() {
	string command; //指令
	stack<string> back, forward;
	string current = "http://www.acm.org/";
	while (cin >> command) {
		if (command == "VISIT") {
			string x;
			forward = stack<string>(); //把forward清空(題目要求)，把下一頁清空
			//把forward清空的第二種方法
			/*while (!forward.empty()) {
				forward.pop();
			}*/

			back.push(current); //把最一開始的網址存入back中
			cin >> x; //讀取要準備去瀏覽的網址
			current = x;
			cout << x << endl;
		}else if (command == "BACK") {
			if (back.empty()) {
				cout << "Ignored" << endl;
				continue;
			}
			forward.push(current);
			current = back.top();
			back.pop();
			cout << current << endl;
		}else if (command == "FORWARD") {
			if (forward.empty()) {
				cout << "Ignored" << endl;
				continue;
			}
			back.push(current);
			current = forward.top();
			forward.pop();
			cout << current << endl;
		}
		else if (command == "QUIT") {
			break;
		}
	}
}
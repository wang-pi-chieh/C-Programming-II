#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

void FIFO(int n){
	queue<int> q;
	q = queue<int>();
	for (int i = 0; i < n; i++){
		string command;
		cin >> command;
		if (command == "IN"){
			int in;
			cin >> in;
			q.push(in);
		}
		else if (command == "OUT"){
			if (q.empty()){
				cout << "None" << endl;
				continue;
			}
			cout << q.front() << endl;
			q.pop();
		}
	}
	return;
}

void FILO(int n){
	stack<int> s;
	s = stack<int>();
	for (int i = 0; i < n; i++){
		
		string command;
		cin >> command;
		if (command == "IN"){
			int in;
			cin >> in;
			s.push(in);
		}
		else if (command == "OUT"){
			if (s.empty()){
				cout << "None" << endl;
				continue;
			}
			cout << s.top() << endl;
			s.pop();
		}
	}
	return;
}

int main(){
	int t;//case
	cin >> t;
	while (t--){
		int n;
		string word;
		cin >> n;
		cin >> word;
		if (word == "FIFO"){
			FIFO(n);
			continue;
		}
		else if (word == "FILO"){
			FILO(n);
			continue;
		}
	}
	return 0;
}
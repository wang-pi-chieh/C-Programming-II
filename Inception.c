#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	int n;
	string command;
	cin >> n;
	stack <string> s;
	string name;
	while (n--){
		cin >> command;
		if (command == "Sleep"){
			cin >> name;
			s.push(name);
		}
		else if (command == "Kick"){
			if (s.empty()){
				continue;
			}
			s.pop();
		}
		else if (command == "Test"){
			if (s.empty()){
				cout << "Not in a dream" << endl;
				continue;
			}
			cout << s.top() << endl;
		}
	}
}
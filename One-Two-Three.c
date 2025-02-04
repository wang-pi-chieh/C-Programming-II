#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
	int t;//case
	cin >> t;
	while (t--){
		string word;
		cin >> word;
		if (word == "one"){
			cout << "1" << endl;
		}
		else if (word[0] == 'o' && word[1] == 'n'){
			cout << "1" << endl;
		}
		else if (word[0] == 'o' && word[2] == 'e'){
			cout << "1" << endl;
		}
		else if (word[1] == 'n' && word[2] == 'e'){
			cout << "1" << endl;
		}
		else if (word == "two"){
			cout << "2" << endl;
		}
		else if (word[0] == 't' && word[1] == 'w'){
			cout << "2" << endl;
		}
		else if (word[0] == 't' && word[2] == 'o'){
			cout << "2" << endl;
		}
		else if (word[1] == 'w' && word[2] == 'o'){
			cout << "2" << endl;
		}
		else if (word == "three"){
			cout << "3" << endl;
		}
		else if (word[0] == 't' && word[1] == 'h' && word[2] == 'r' && word[3] == 'e'){
			cout << "3" << endl;
		}
		else if (word[0] == 't' && word[1] == 'h' && word[2] == 'r' && word[4] == 'r'){
			cout << "3" << endl;
		}
		else if (word[0] == 't' && word[1] == 'h' && word[3] == 'e' && word[4] == 'e'){
			cout << "3" << endl;
		}
		else if (word[0] == 't' && word[2] == 'r' && word[3] == 'e' && word[4] == 'e'){
			cout << "3" << endl;
		}
		else if (word[1] == 'h' && word[2] == 'r' && word[3] == 'e' && word[4] == 'e'){
			cout << "3" << endl;
		}
	}
	return 0;
}
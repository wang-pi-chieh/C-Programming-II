#include <iostream>
using namespace std;
 
int main() {
    int n, f;
    long long area, animal, eco;
    long long award;
     
    cin >> n;
    while (n--) {
        cin >> f;
        award = 0;
        for (int i=0; i<f; i++) {
            cin >> area >> animal >> eco;
            award += area * eco;
        }
        cout << award << endl;
    }
    return 0;
}
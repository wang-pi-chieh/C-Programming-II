#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
 
int main() {
    int n;
    while (cin >> n){
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int mid1 = a[(n-1)/2];
        int mid2 = a[n/2];
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (a[i] == mid1 || a[i] == mid2) ans++;
        }
        cout << mid1 << " " << ans << " " << mid2 - mid1 + 1 << "\n";
    }
    return 0;
}
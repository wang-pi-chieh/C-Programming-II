#include <stdio.h>
//注意事項:
// 每個元素不大於2^32，即要用long long

//#define n 100

int main() {
    int t, n, i, c;
    scanf("%d", &c); // Input the number of test cases，有幾筆測資

    for (t = 1; t <= c; t++) { //case
        scanf("%*s%*s%d", &n); // Input the matrix size, skipping the first two strings，輸入矩陣大小
        long long mat[n * n]; // Using a one-dimensional array

        for (i = 0; i < n * n; i++) { // Input the matrix numbers，輸入矩陣元素值
            scanf("%lld", &mat[i]);
        }

        for (i = 0; i < n * n; i++) { // Checking symmetry
            if (mat[i] != mat[(n * n - 1) - i] || mat[i] < 0) { //對稱矩陣: 所有元素均為正數
                break;
            }
        }

        if (i == n * n) { // If the loop wasn't broken, it's a symmetric matrix 
            //括號成立時表示已經檢查完矩陣中的所有元素
            printf("Test #%d: Symmetric.\n", t);
        }
        else {
            printf("Test #%d: Non-symmetric.\n", t);
        }
    }
    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#pragma warning(disable:4996)
//
//int main() {
//	int m, n; //n: number 0, m: number 1
//	scanf("%d%d", &n, &m);
//
//	if (abs(m - n) != 1) {
//		printf("-1");
//	}
//	
//	while (m > 0 || n > 0) {
//
//	}
//
//}

#include <stdio.h>

int main() {
    long long n, m;  //n: number 0, m: number 1
    // 讀取 n 和 m
    scanf("%lld %lld", &n, &m);

    // 如果無法滿足要求，輸出 -1
    if (m >= 2 * n + 3 || n - m >= 2) {
        printf("-1\n");
    }
    else if (m == 2 * n + 2) { // 如果 m 比 2*n+2 大
        // 輸出一系列 "110"，再加上 "11"
        for (long long i = 1; i <= n; i++)
            printf("110");
        printf("11\n");
    }
    else if (m == 2 * n + 1) { // 如果 m 比 2*n+1 大
        // 輸出一系列 "110"，再加上 "1"
        for (long long i = 1; i <= n; i++)
            printf("110");
        printf("1\n");
    }
    else if (m > n) { // 如果 m 大於 n，表示 1 的數量比 0 多
        // 不斷輸出 "110" 直到 m 和 n 相等
        while (m > n) {
            printf("110");
            m -= 2;
            n -= 1;
        }
        // 輸出一系列 "10"
        for (long long i = 1; i <= n; i++)
            printf("10");
        printf("\n");
    }
    else if (n == m) { // 如果 n 和 m 相等，表示 0 和 1 的數量相等
        // 輸出一系列 "10"
        for (long long i = 1; i <= n; i++)
            printf("10");
        printf("\n");
    }
    else { // 如果 n 大於 m，表示 0 的數量比 1 多
        // 不斷輸出 "010" 直到 n 和 m 相等
        while (n > m) {
            printf("010");
            n -= 2;
            m--;
        }
        // 輸出一系列 "10"
        for (long long i = 1; i <= n; i++)
            printf("10");
        printf("\n");
    }

    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#pragma warning(disable:4996)
//
////int compare(const void* p, const void* q);
//int max(int, int);
//
//struct things {
//	int v;
//	int w;
//};
//
//things item[110];
//
//int main() {
//	int N, W;
//	scanf("%d%d", &N, &W);
//	int dp[101][10001] = { 0 };
//
//	for (int i = 0; i < N; i++) {
//		scanf("%d%d", &item[i].v, &item[i].w);
//	}
//	//qsort(item, N, sizeof(struct things), compare);
//
//	/*for (int i = 0; i < N; i++) {
//		printf("%d %d\n", item[i].v, item[i].w);
//	}*/
//
//	//memset(dp, 0, sizeof(dp));
//	for (int i = 0; i <= N; i++) {
//		for (int j = 0; j <= W; j++) {
//			if (j < item[i].v) {
//				dp[i + 1][j] = dp[i][j];
//			}
//			else {
//				dp[i + 1][j] = max(dp[i][j], dp[i][j - item[i].v] + item[i].v * item[i].w);
//			}
//		}
//	}
//}
//
//int max(int a, int b) {
//	return (a > b) ? a : b;
//}
//
////int compare(const void* p, const void* q) {
////	int A = *(int*)p;
////	int B = *(int*)q;
////
////	if (A == B) {
////		return 0;
////	}
////	return (A < B) ? -1 : 1; //注意排序順序，需要從大到小排列
////}

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define max_N 100
#define max_W 10000

int dp[max_N + 1][max_W + 1] = { 0 }; //需要max_N+1和max_W+1的原因是多一個位子給結束符號

int max(int, int);

struct things {
	int v;
	int w;
};

struct things item[110];

int main() {
	int N = 0, W = 0;
	scanf("%d%d", &N, &W);
	
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &item[i].v, &item[i].w);
	}

	for (int i = 0; i <= N; i++) {  //i:column(第幾個物品) //j:row(重量多少)
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) {  
				dp[i][j] = 0;
			}
			else if(item[i - 1].w <= j) { //裝得下，開始討論裝好還是不裝好
				dp[i][j] = max(dp[i - 1][j - item[i - 1].w] + item[i - 1].v, dp[i - 1][j]);  //max(a,b) a是裝，b是不裝
				//裝的狀況: 當今天只裝了i-1個物品時的價值，再加上第i個物品的價值
			}
			else { //放不下
				dp[i][j] = dp[i - 1][j];
			}
			
		}
		//printf("\n");
	}
	printf("%d\n", dp[N][W]);
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

//int compare(const void* p, const void* q) {
//	int A = *(int*)p;
//	int B = *(int*)q;
//
//	if (A == B) {
//		return 0;
//	}
//	return (A < B) ? -1 : 1; //注意排序順序，需要從大到小排列
//}
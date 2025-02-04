#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

int main() {
	int n; //n: level number
	scanf("%d", &n);
	int p, q; //X和Y有幾個數
	int X[100], Y[100];
	scanf("%d", &p);
	for (int i = 0; i < p; i++) {
		scanf("%d", &X[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &Y[i]);
	}

	/*for (int i = 0; i < p; i++) {
		printf("%d ", X[i]);
	}
	printf("\n");
	for (int i = 0; i < q; i++) {
		printf("%d ", Y[i]);
	}*/

	int test = 1; //指level 1
	bool flag;
	int num;
	while (test <= n) {
		flag = true;
		//判斷1~n每個數都在
		if (p > q) {
			num = p;
		}
		else {
			num = q;
		}

		for (int i = 0; i < num; i++) {
			if (test == X[i] || test == Y[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("Oh, my keyboard!");
			break;
		}
		test++;
	}
	if (flag == false) {
		printf("I become the guy.");
	}
	

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int n; //表要找的錢
	
	int coin[10] = { 10000,5000,1000,500,100,50,10,5,1 };
	int num;

	while (scanf("%d", &n) != EOF) {
		num = 0;
		for (int i = 0; i < 9; i++) {
			num = num + n / coin[i];
			n %= coin[i];

		}
		printf("%d\n", num);
		
	}
	return 0;
}
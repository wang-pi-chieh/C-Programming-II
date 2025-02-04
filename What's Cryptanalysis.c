#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	char word[999];  //為什麼是開999
	getchar();
	//是單測資，n代表的含意是有幾行輸入，而非有幾筆測資

	char character[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int count[26] = { 0 };// 26個字母

	while (n > 0) {  //n為什麼要加等於
		gets(word);
		n--;
		for (int i = 0; i < strlen(word); i++) {  //全部轉大寫  //要一個一個轉
			word[i] = toupper(word[i]);
		}
		
		for (int i = 0; i < strlen(word); i++) {
			for (int j = 0; j < 26; j++) {
				if (word[i] == character[j]) {
					//printf("F\n");
					count[j]++;
					//printf("%c %d\n", character[j], count[j]);
				}
			}
		}
	}

	/*for (int i = 0; i < 26; i++) {
		printf("%d\n", count[i]);
	}*/

	for (int i = 999; i > 0; i--) {
		//printf("a\n");
		for (int j = 0; j < 26; j++) {
			//printf("f\n");
			if (count[j] == i) {
				printf("%c %d\n", j + 65, i);
			}
		}

	}
}
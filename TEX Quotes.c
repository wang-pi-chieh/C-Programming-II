#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	char word[10000] = { 0 };
	while (gets_s(word)) {
		int count = strlen(word);
		int n = 0;//計算是開頭還是結尾 //0是開頭，1是結尾
		for (int i = 0; i < count; i++) {
			if (word[i] == 34 && n == 0) {  // " == 34
				printf("``");
				n = n + 1;
			}
			else if (word[i] == 34 && n == 1) {
				printf("''");
				n = n - 1;
			}

			else {
				printf("%c", word[i]);
			}
		}
		printf("\n");

	}
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	char c;
	int n = 0;
	while (scanf("%c", &c) != EOF) {
		if (c == '"' && n == 0) {  // " == 34
			n = n - 1;
			printf("``");

		}
		else if (c == '"' && n < 0) {
			n = n + 1;
			printf("''");

		}
		else {
			printf("%c", c);
		}
	}
	return 0;
}


#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main() {

	char chr;
	bool flag = true;

	while ((chr = getchar()) != EOF) {
		if (flag && chr == '"') {
			printf("``");
			flag = false;
		}
		else if (!flag && chr == '"') {
			printf("''");
			flag = true;
		}
		else {
			printf("%c", chr);
		}
	}

	return 0;
}
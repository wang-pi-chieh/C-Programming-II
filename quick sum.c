#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

//題目意思:the sum of (第幾個字元)x(ASCII CODE)
//注意事項:
// 只有大寫和空白鍵(ASCII CODE先表示為0)
// 遇到#則結束
// 最多255字元


int main() {
	char word[260] = { 0 }; //輸入的文字

	//char A = 65;ASCII CODE
	char test[5] = "#";
	char space[5] = " ";
	while (gets_s(word)) { //用gets_s來進行input，因為讀到空格不會認定為結束input
		int n = strlen(word); //總共有幾個字
		if (strcmp(word, test) == 0) {  //讀到'#'，則結束
			break;
		}
		int sum = 0; //等等輸出用

		for (int i = 0; i < n; i++) {
			if (word[i] == ' ') {
				/*isspace(word[i])*/
				sum = sum + 0;
			}
			else {
				sum = sum + (i + 1) * (word[i] - 64);
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
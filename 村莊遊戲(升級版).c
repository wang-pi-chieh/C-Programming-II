#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable:4996)

void print_maze(int maze[10][10], int, int, int, int);

int main() {
	int A_goal_X = 8, A_goal_Y = 8, B_goal_X = 1, B_goal_Y = 1;
	char ans; 

	int score_A = 0;
	int score_B = 0;

	FILE* fptr = fopen("計分表.txt", "r"); //模式要用r，才不會在重新開檔時，又把score_A=0和score_B=0讀進去
	fscanf(fptr, "Player1 %d", &score_A);
	fscanf(fptr, "Player2 %d", &score_B);
	fclose(fptr);
	

	do {
		int A_X = 1, A_Y = 1, B_X = 8, B_Y = 8;

		int maze[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //2的位置是A或B
		{1, 2, 0, 0, 1, 0, 0, 0, 0, 1},  //要把陣列放在do...while裡面，這樣重新開始時會重新輸出遊戲開始時的迷宮
		{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
		{1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 1, 1},
		{1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 3, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		};

		print_maze(maze, A_X, A_Y, B_X, B_Y);
		
		while (A_X != A_goal_X || A_Y != A_goal_Y || B_X != B_goal_X || B_Y != B_goal_Y) {
			char ch = getch();		
			
			if (ch == 'w' && maze[A_X - 1][A_Y] != 1) { //要多判斷是不是牆壁
				maze[A_X][A_Y] = 0;
				A_X--;
			}
			else if (ch == 'a' && maze[A_X][A_Y - 1] != 1) {
				maze[A_X][A_Y] = 0;
				A_Y--;
			}
			else if (ch == 's' && maze[A_X + 1][A_Y] != 1) {
				maze[A_X][A_Y] = 0;
				A_X++;
			}
			else if (ch == 'd' && maze[A_X][A_Y + 1] != 1) {
				maze[A_X][A_Y] = 0;
				A_Y++;
			}


			if (ch == '5' && maze[B_X - 1][B_Y] != 1) {
				maze[B_X][B_Y] = 0;
				B_X--;
			}
			else if (ch == '1' && maze[B_X][B_Y - 1] != 1) {
				maze[B_X][B_Y] = 0;
				B_Y--;
			}
			else if (ch == '2' && maze[B_X + 1][B_Y] != 1) {
				maze[B_X][B_Y] = 0;
				B_X++;
			}
			else if (ch == '3' && maze[B_X][B_Y + 1] != 1) {
				maze[B_X][B_Y] = 0;
				B_Y++;
			}
			
		/*	score_A = 0;
			score_B = 0;*/
			
			system("cls");
			print_maze(maze, A_X, A_Y, B_X, B_Y);

			if (A_X == A_goal_X && A_Y == A_goal_Y) {  //要注意最後一步放的位置，會影響到是不是要多按一步，才可以顯示出有人贏了
				printf("Player A wins\n");
				score_A++;
				break;
			}
			if (B_X == B_goal_X && B_Y == B_goal_Y) {
				printf("Player B wins\n");
				score_B++;
				break;
			}
		}

		//fseek(fptr, 0, SEEK_SET);
		
		printf("Score:\n");
		printf("Player1: %d\n", score_A);
		printf("Player2: %d\n", score_B);

		FILE* fptr = fopen("計分表.txt", "w");
		fprintf(fptr, "Player1 %d\n", score_A);
		fprintf(fptr, "Player2 %d\n", score_B);
		fclose(fptr);
	
		printf("Player again?(Y/N)\n");
		scanf("%c", &ans);//先用scanf讀是否要再玩一次
		getchar(); //用途:會讀取並丟棄輸入緩衝區的下一個字符(多為換行符)，從而清理輸入緩衝區，避免影響後續的輸入讀取

		if (ans == 'Y'){ //再判斷是Y還是N，Y的話用是清屏，N的話是結束
			system("cls");
		}
		else {
			break;
		}
		//ask = getch();
	} while (ans == 'Y');
	
	
}

void print_maze(int maze[10][10], int A_X, int A_Y, int B_X, int B_Y) { //輸入值是A和B的X.Y座標
	for (int i = 0; i < 10; i++) { //列
		for (int j = 0; j < 10; j++) { //行
			if (i == A_X && i == B_X && j == A_Y && j == B_Y) { //i和j用表示現在的位置，所以要用i是不是A_X和i是不是B_X來判斷，而不是A_X==B_X，因為這樣是判斷A_X是不是B_X的意思
				printf("S");
			}
			else if (i == A_X && j == A_Y) {  //用A_X==i和A_Y==j的方式，寫入A
				printf("A");
			}
			else if (i == B_X && j == B_Y) {  //用B_X==i和B_Y==j的方式，寫入B
				printf("B");
			}
			else if (maze[i][j] == 0) {
				printf(" ");
			}
			else if (maze[i][j] == 1) {
				printf("#");
			}
			
		}
		printf("\n");
	}
	printf("Player 1(A) control: w(up) a(left) s(down) d(right)\n");
	printf("Player 2(B) control: 5(up) 1(left) 2(down) 3(right)\n");
}
//寫迷宮的function
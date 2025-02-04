#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable:4996)

void print_maze(int maze[10][10], int, int, int, int);

int main() {
	char ans = 'Y';
	const int goal_A_X = 8, goal_A_Y = 8, goal_B_X = 1, goal_B_Y = 1;
	//把A和B的目標位置寫死

	do {
		int A_X = 1, A_Y = 1, B_X = 8, B_Y = 8;
		//A和B一開始的位置
		ans = 'Y';

		int maze[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //2的位置是A或B
		{1, 2, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
		{1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 1, 1},
		{1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 2, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		};

		print_maze(maze, A_X, A_Y, B_X, B_Y);  //開始寫迷宮
		printf("Player 1(A) control: w(up) a(left) s(down) d(right)\n");
		printf("Player 2(B) control: 5(up) 1(left) 2(down) 3(right)\n");

		char ch;

		while (A_X != goal_A_X || A_Y != goal_A_Y || B_X != goal_B_X || B_Y != goal_B_Y) {  //用while去判斷當A的X或Y值和B的X或Y值，其中一個不等於就執行
			ch = getch(); //用getch()輸入，並用ch紀錄我按哪顆鍵
			//下面的if判斷當輸入的方向和移動後不會是牆壁時執行
			//注意上下左右對應到X和Y的加減(往上是X+1，往下X-1，往左y-1，往右y+1)
			if (ch == 'w' && maze[A_X - 1][A_Y] != 1) {
				maze[A_X][A_Y] = 0; //把原本的那個位置改成0，才不會出現兩個A或兩個B
				A_X = A_X - 1; //改變A或B的位置
			}

			if (ch == 'a' && maze[A_X][A_Y - 1] != 1) {
				maze[A_X][A_Y] = 0;
				A_Y = A_Y - 1;
			}

			if (ch == 's' && maze[A_X + 1][A_Y] != 1) {
				maze[A_X][A_Y] = 0;
				A_X = A_X + 1;
			}

			if (ch == 'd' && maze[A_X][A_Y + 1] != 1) {
				maze[A_X][A_Y] = 0;
				A_Y = A_Y + 1;
			}

			if (ch == '5' && maze[B_X - 1][B_Y] != 1) {
				maze[B_X][B_Y] = 0;
				B_X = B_X - 1;
			}

			if (ch == '1' && maze[B_X][B_Y - 1] != 1) {
				maze[B_X][B_Y] = 0;
				B_Y = B_Y - 1;
			}

			if (ch == '2' && maze[B_X + 1][B_Y] != 1) {
				maze[B_X][B_Y] = 0;
				B_X = B_X + 1;
			}

			if (ch == '3' && maze[B_X][B_Y + 1] != 1) {
				maze[B_X][B_Y] = 0;
				B_Y = B_Y + 1;
			}

			system("cls");  //把程式碼清空
			print_maze(maze, A_X, A_Y, B_X, B_Y);  //重新輸出一次迷宮

			if (A_X == goal_A_X && A_Y == goal_A_Y) { //如果A的X和Y都跟B原本的X和Y相同的話，即Break，跳出這個迴圈(do..while)
				printf("Player A wins\n");
				break;
			}

			if (B_X == goal_B_X && B_Y == goal_B_Y) { //如果B的X和Y都跟A原本的X和Y相同的話，即Break，跳出這個迴圈(do..while)
				printf("Player B wins\n");
				break;
			}

		}
		printf("Play again?(Y/N)\n");
		scanf("%c", &ans);
		getchar(); //必須要用getchar()
		if (ans == 'Y') {
			system("cls");
		}
		else {
			break;
		}
	} while (ans == 'Y');
}


void print_maze(int maze[10][10], int X, int Y, int x, int y) {  //X=A_X, Y=A_Y, x=B_X, y=B_Y
	//要注意判斷順序!!
	for (int i = 0; i < 10; i++) { //i is row
		for (int j = 0; j < 10; j++) { //j is column
			if (i == X && i == x && j == Y && j == y) {  //重疊的狀況
				printf("S");
			}
			else if (i == x && j == y) { //放B的位置
				printf("B");
			}
			else if (i == X && j == Y) { //放A的位置
				printf("A");
			}
			else if (maze[i][j] == 0) {  //遇到0的時候，是空格
				printf(" ");
			}
			else if (maze[i][j] == 1) {  //遇到1的時候，是#
				printf("#");
			}
		}
		printf("\n");
	}
}


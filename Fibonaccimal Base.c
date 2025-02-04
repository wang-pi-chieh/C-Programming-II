#include<stdio.h>
#include<stdbool.h>

int main(){

    int N;
    int Fibonacci[40] = {0, 1};
    int i;

    for(i = 2; i < 40; i++){
        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
    }

    scanf("%d", &N);

    while(N--){

        int num;
        bool flag = false;

        scanf("%d", &num);
        printf("%d = ", num);

        for(i = 39; i >= 2; i--){
            if(num >= Fibonacci[i]){
                num = num - Fibonacci[i];
                flag = true;
                printf("1");
            }
            else if(flag){
                printf("0");
            }
        }

        printf(" (fib)\n");
    }

    return 0;
}
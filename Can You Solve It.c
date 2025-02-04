#include <stdio.h>

int main() {
    int T;
    long long x, y, n, step1, step2;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; Case++){
        printf("Case %d: ", Case);
        scanf("%lld %lld", &x, &y);
        if (x == 0 && y == 0) step1 = 0;
        else {
            n = x + y - 1;
            step1 = (n * n + 3 * n) / 2 + (x + 1);
        }
        scanf("%lld %lld", &x, &y);
        n = x + y - 1;
        if (x == 0 && y == 0) step2 = 0;
        else {
            n = x + y - 1;
            step2 = (n * n + 3 * n) / 2 + (x + 1);
        }
        printf("%lld\n", step2 - step1);
    }
    return 0;
}

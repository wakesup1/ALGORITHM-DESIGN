#include<stdio.h>

int dp[3];

int main () {
    int n;
    scanf("%d", &n);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 0; i <n-1;i++) {
        dp[2] = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    printf("%d", dp[2]);
}
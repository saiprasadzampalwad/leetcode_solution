int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        dp[i] = INT_MAX;
        for (int j = 0; j < coinsSize; ++j) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = dp[i - coins[j]] + 1 < dp[i] ? dp[i - coins[j]] + 1 : dp[i];
            }
        }
    }
    int result = dp[amount] == INT_MAX ? -1 : dp[amount];
    free(dp);
    return result;
}
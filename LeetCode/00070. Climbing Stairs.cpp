class Solution {
public:
    int climbStairs(int n) {
        int dp[46] = {0,};
        dp[1] = 1, dp[2] = 2;
        for(int i = 3; i < 46; i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};

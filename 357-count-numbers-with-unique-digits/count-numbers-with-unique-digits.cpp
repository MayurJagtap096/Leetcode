class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[9];
        dp[0] = 1;
        dp[1] = 10;
        dp[2] = 91;
        if(n<3) return dp[n];
        for(int i=3; i<=n; i++){
            int count = 9;
            int ans = 9;
            for(int j=1; j<i; j++){
                ans = ans * count;
                count--;
            }
            dp[i] = dp[i-1] + ans;
        }
        return dp[n];
    }
};
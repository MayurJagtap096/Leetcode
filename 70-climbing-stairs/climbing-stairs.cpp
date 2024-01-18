class Solution {
public:
    int ans=0;
    int dp[46] = {};
    int solve(int n) {
        if(n<0) return 0;
        if(dp[n]!=0) return dp[n];
        if(n==0) return 1;
        ans = solve(n-1) + solve(n-2);
        dp[n]=ans;
        return ans;
    }
    int climbStairs(int n) {
        return solve(n);
    }   
};
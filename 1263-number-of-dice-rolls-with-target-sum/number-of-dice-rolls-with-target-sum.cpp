class Solution {
public:
    int mod = 1e9+7;
    int solve(int n,int k,int sum,vector<vector<int>> &dp){
        if(n==0 || sum<=0){
            if(n==0 && sum==0) return 1;
            return 0;
        }
        if(dp[n][sum]!=-1) return dp[n][sum];
        int res=0;
        for(int i=1;i<=k;i++){
            res = (res + solve(n-1,k,sum-i,dp)) % mod;
        }
        return dp[n][sum] = res;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n,k,target,dp);
    }
};
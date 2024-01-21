class Solution {
private:
    int solve(vector<int> nums,int i,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        dp[i] = max(nums[i]+solve(nums,i+2,dp),solve(nums,i+1,dp));
        return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size()+1,-1);
        int ans = max(solve(nums,0,dp),solve(nums,1,dp));
        return ans;
    }
};
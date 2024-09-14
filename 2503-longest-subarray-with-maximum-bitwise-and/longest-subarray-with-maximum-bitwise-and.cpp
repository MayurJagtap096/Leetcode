class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int temp = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxi) temp++;
            else temp = 0;
            ans = max(ans, temp);
        }
        return ans;   
    }
};
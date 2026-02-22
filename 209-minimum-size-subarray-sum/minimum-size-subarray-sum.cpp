class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, minLen = INT_MAX, sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            while(sum>=target) {
                minLen = min(minLen, i-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
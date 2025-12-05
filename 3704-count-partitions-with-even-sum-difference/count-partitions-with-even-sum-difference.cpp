class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0;
        int right = 0;
        int left = 0;
        for(int a: nums) {
            right += a;
        }
        for(int i=0;i<nums.size()-1;i++) {
            left = left + nums[i];
            right = right - nums[i];
            if((left-right)%2==0) ans++;
        }
        return ans;
    }
};
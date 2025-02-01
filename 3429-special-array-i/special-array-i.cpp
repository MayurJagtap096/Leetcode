class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool ans=true;
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size()-1;i++) {
            if((nums[i]%2 == 0 && nums[i+1]%2 == 0) || (nums[i]%2 != 0 && nums[i+1]%2 != 0)) {
                ans = false;
                break;
            }
            else {
                continue;
            }
        }
        return ans;
    }
};
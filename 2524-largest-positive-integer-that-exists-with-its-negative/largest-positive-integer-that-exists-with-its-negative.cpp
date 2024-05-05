class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                for(int j=0;j<nums.size();j++)
                {
                    if(nums[i]*-1 == nums[j])
                    {
                        ans = max(nums[j],ans);
                    }
                }
            }
        }
        if(ans==INT_MIN) return -1;
        return ans;    
    }
};
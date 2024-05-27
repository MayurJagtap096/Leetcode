class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        int maxi = *max_element(nums.begin(),nums.end());
        for(int i=0;i<=maxi;i++)
        {
            int temp=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j] >= i) temp++;
            }
            if(temp==i) return i;
        }
        return -1;
    }
};
class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>0 && std::binary_search(nums.begin(),nums.end(),-nums[i]))
            {
                return nums[i];
            }
        }
        return -1;
    }
};
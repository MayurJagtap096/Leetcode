class Solution {
public:
    
    void solve(int index, vector<int>& nums, unordered_map<int,int> &m, int k, int &ans)
    {
        if(index>=nums.size())
        {
            ans++;
            return ;
        }

        solve(index+1,nums,m,k,ans);

        if(!m[nums[index]-k] && !m[nums[index]+k])
        {
            m[nums[index]]++;
            solve(index+1,nums,m,k,ans);
            m[nums[index]]--;
        }

    }

    int beautifulSubsets(vector<int>& nums, int k) 
    {
        int ans=0;
        unordered_map<int,int> m;
        solve(0, nums, m, k, ans);
        return ans-1;
    }
};
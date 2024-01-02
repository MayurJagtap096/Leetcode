class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++) {
            int freq = m[nums[i]];
            if(freq == ans.size()){
                ans.push_back({});
            }
            ans[freq].push_back(nums[i]);
            m[nums[i]]++;
        }
        return ans;
    }
};
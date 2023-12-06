class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int a:nums) m[a]++;
        for(auto a:m){
            if(a.second==1) ans.push_back(a.first);
        }
        return ans;
    }
};
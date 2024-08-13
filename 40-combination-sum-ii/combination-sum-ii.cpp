class Solution {
public:

    void solve(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> curr, int idx) {
        if(target < 0) return ;
        if(target == 0) {
            ans.push_back(curr);
            return ;
        }
        for(int i=idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ans, curr, i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, ans, curr, 0);
        
        return ans;
    }
};
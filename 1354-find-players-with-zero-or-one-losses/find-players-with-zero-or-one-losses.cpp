class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> m;
        vector<vector<int>> ans(2,vector<int>());
        for(int i=0;i<matches.size();i++) {
            m[matches[i][1]]++;
        }
        set<int> temp1,temp2;
        for(int i=0;i<matches.size();i++) {
            if(m[matches[i][0]]==0) temp1.insert(matches[i][0]);
            if(m[matches[i][0]]==1) temp2.insert(matches[i][0]);
            if(m[matches[i][1]]==1) temp2.insert(matches[i][1]);
        }
        for(int a:temp1) ans[0].push_back(a);
        for(int a:temp2) ans[1].push_back(a); 
        return ans;
    }
};
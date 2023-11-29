class Solution {
public:
    void help(int i, int sum, int k, int n, vector<vector<int>> &ans, vector<int> &subset){
        if(k==0){
            if(sum==n) ans.push_back(subset);
            return;
        }
        if(i==10) return;
        // pick a number
        sum+=i;
        subset.push_back(i);
        help(i+1,sum,k-1,n,ans,subset);
        sum-=i;
        subset.pop_back();

        // ignore a number
        help(i+1,sum,k,n,ans,subset);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        help(1,0,k,n,ans,subset);
        return ans;    
    }
};
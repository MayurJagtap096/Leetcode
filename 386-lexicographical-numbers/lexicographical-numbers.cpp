class Solution {
public:

    void solve(int curr, int n, vector<int>& ans) {
        if(curr > n) return;
        ans.push_back(curr);
        for(int append = 0; append <=9; append++) {
            int newNum = (curr * 10) + append;
            if(newNum > n) return ;
            solve(newNum, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int start = 1; start <= 9; start++) {
            solve(start, n, ans);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        long long suff = 1, pref = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans[i][j] = pref;
                pref = pref * grid[i][j] % 12345;
            }
        }
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                ans[i][j] = ans[i][j]*suff%12345;
                suff = suff * grid[i][j]%12345;
            }
        }
        return ans;
    }
};
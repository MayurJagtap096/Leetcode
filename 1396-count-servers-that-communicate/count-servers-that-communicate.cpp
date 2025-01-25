class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // vectors to store the row sum and col sum
        vector<int> rowServerSum(grid.size());
        vector<int> colServerSum(grid[0].size());
        int ans=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                rowServerSum[i] += grid[i][j];
                colServerSum[j] += grid[i][j];
            }
        }
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    if(rowServerSum[i]>1) ans++;
                    else if(colServerSum[j]>1) ans++;
                }
            }
        }
        return ans;
    }
};
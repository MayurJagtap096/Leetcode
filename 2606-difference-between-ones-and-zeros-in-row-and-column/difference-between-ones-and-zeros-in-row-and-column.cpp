class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row1(m,0),row0(m,0);
        vector<int> col1(n,0),col0(n,0);
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    row0[i]++;
                    col0[j]++;
                }
                if(grid[i][j]==1){
                    row1[i]++;
                    col1[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(row1[i]+col1[j]-row0[i]-col0[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
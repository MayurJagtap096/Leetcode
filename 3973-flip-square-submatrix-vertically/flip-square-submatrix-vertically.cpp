class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int c;
        for(int i=x, c=x+k-1; i<c; i++, c--) {
            for(int j=y; j<y+k; j++) {
                swap(grid[i][j], grid[c][j]);
            }
        }
        return grid;
    }   
};
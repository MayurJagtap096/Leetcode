class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    bool canCommunicate = false;
                    // we found a server
                    // check if it can communicate with other server
                    
                    // firstly checking in the same row if the server is available
                    for(int col=0;col<n;col++) {
                        if(grid[i][col]==1 && col!=j) {
                            canCommunicate = true;
                            ans+=1;
                            break;
                        }
                    }
                    // If we dont find another server in same row then checking in the column
                    if(!canCommunicate) {
                        for(int row=0;row<m;row++) {
                            if(grid[row][j]==1 && row!=i) {
                                ans+=1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
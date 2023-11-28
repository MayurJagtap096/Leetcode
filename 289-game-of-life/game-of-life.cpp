class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
        vector<vector<int>> temp = board;
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int live = 0;
                if( i > 0){
                    if(temp[i-1][j] == 1)
                        live++; //top
                    if( j > 0)
                        if(temp[i-1][j-1] == 1) 
                            live++; //top left corner
                }

                if( i+1 < m){
                    if(temp[i+1][j] == 1)
                        live++; // bottom
                    if( j+1 < n)
                        if(temp[i+1][j+1] == 1)
                            live++; // bottom right corner
                }
                
                if( j > 0){
                    if(temp[i][j-1] == 1)
                        live++; // left
                    if( i+1 < m)
                        if(temp[i+1][j-1] == 1) 
                            live++; //bottom left corner
                }

                if( j+1 < n){
                    if(temp[i][j+1] == 1)
                        live++; // right
                    if( i> 0)
                        if(temp[i-1][j+1] == 1) 
                            live++; //top right corner
                }
                
                cout<<live<<endl;
                if( board[i][j] == 0){
                    if( live == 3)
                        board[i][j] = 1;
                }
                else{
                    if( live < 2 || live > 3)
                        board[i][j] = 0;
                }
            }
        }
    }
};
class Solution {
public:
    bool solve(int i, int j, int n, int m,vector<vector<char>>& board, string &word, int k){
        if(i<0 || j<0 || i>=n || j>=m || word[k]!=board[i][j]) return false;
        if(k==word.size()-1) return true;
        char temp = board[i][j];
        board[i][j]='#';
        bool op1 = solve(i+1,j,n,m,board,word,k+1);
        bool op2 = solve(i,j+1,n,m,board,word,k+1);
        bool op3 = solve(i-1,j,n,m,board,word,k+1);
        bool op4 = solve(i,j-1,n,m,board,word,k+1);
        board[i][j]=temp;
        return op1||op2||op3||op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,n,m,board,word,0)) return true;
                }
            }
        }  
    return false;
    }
};
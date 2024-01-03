class Solution {
public:
    bool isSafe(int i,int j,vector<string>&temp){
        int x=i,y=j;
        while(x>=0){
            if(temp[x][y]=='Q')return false;
            x--;
        }
        x=i;
        y=j;
        while(x>=0 && y>=0){
            if(temp[x][y]=='Q')return false;
            x--;
            y--;
        }
        x=i;
        y=j;
        while(x>=0 && y<temp.size()){
            if(temp[x][y]=='Q')return false;
            x--;
            y++;
        }
        return true;
    }
    void solve(int i, int n, vector<string> &temp, vector<vector<string>> &ans) {
        if(i==n){
            ans.push_back(temp);
            return ;
        }
        for(int j=0;j<n;j++){
            if(isSafe(i,j,temp)){
                temp[i][j]='Q';
                solve(i+1,n,temp,ans);
                temp[i][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp;
        vector<vector<string>> ans;
        string s;
        for(int i=0;i<n;i++) s+='.';
        for(int i=0;i<n;i++) temp.push_back(s);
        solve(0,n,temp,ans);
        return ans;
    }
};
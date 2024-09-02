class Solution {
public:

    void rec(int node,int end,vector<vector<int>>&g,vector<int>&vis){
        vis[node]=1;
        for(auto i:g[node]){
            if(!vis[i])
                rec(i,end,g,vis);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>g(n);
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        rec(source,destination,g,vis);
        return vis[destination];
    }
};
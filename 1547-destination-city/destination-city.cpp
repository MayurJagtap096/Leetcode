class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> m;
        for(int i=0;i<paths.size();i++){
            m[paths[i][0]]++;
            cout<<m[paths[i][0]];
        }
        for(int i=0;i<paths.size();i++){
            for(int j=0;j<2;j++){
                if(m[paths[i][j]]==0) return paths[i][j];
            }
        }
        return "";
    }
};
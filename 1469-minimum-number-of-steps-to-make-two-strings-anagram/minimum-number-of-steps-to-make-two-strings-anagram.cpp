class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        unordered_map<char,int> m;
        for(char c:s) m[c]++;
        for(char c:t) m[c]--;
        for(auto a:m) if(a.second<0) ans+=(a.second)*-1;
        return ans;
    }
};
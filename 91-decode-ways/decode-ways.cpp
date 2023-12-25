class Solution {
public:
    int mem[101];
    int solve(int i, string &s, int &n){
        if(mem[i]!=-1) return mem[i];
        if(i==n) return mem[i] = 1;
        if(s[i]=='0') return mem[i] = 0;
        int res = solve(i+1,s,n);
        if(i+1<n){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
                res += solve(i+2,s,n);
            }
        }
        return mem[i] = res;
    }
    int numDecodings(string s) {
        int n = s.length();
        memset(mem,-1,sizeof(mem));
        return solve(0,s,n);
    }
};
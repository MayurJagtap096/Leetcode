class Solution {
public:
    int solve(int n,vector<int> &t){
        if(n==1) return n;
        if(t[n]!=-1) return t[n];
        int result = INT_MIN;
        for(int i=1;i<n;i++){
            int prod = i * max(n-i,solve(n-i,t));
            result = max(result,prod);
        }
        return t[n] = result;
    }
    int integerBreak(int n) {
        vector<int> t(n+1,-1);
        return solve(n,t);
    }
};
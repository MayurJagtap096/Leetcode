class Solution {
public:
    int n;
    int memo[50001];
    int findIndex(vector<vector<int>> &v, int l, int currEnd) {
        int r = n-1;
        int res = n+1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(v[mid][0]>=currEnd) {
                res = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return res;
    }

    int solve(vector<vector<int>> &v, int i) {
        if(i>=n) return 0;
        if(memo[i]!=-1) return memo[i];
        int nextIndex = findIndex(v,i+1,v[i][1]);
        int taken = v[i][2] + solve(v,nextIndex);
        int notTaken = solve(v,i+1);
        return memo[i] = max(taken, notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(memo,-1,sizeof(memo));
        vector<vector<int>> v(n,vector<int>(3,0));
        for(int i=0;i<n;i++) {
            v[i][0] = startTime[i];
            v[i][1] = endTime[i];
            v[i][2] = profit[i];
        }
        auto com = [&](auto &v1, auto &v2){
            return v1[0]<=v2[0];
        };
        sort(v.begin(),v.end(),com);
        return solve(v,0);
    }
};
#include <vector>
using namespace std;

class Solution {
public:
    int ans = 0;
    const int MOD = 1000000007;
    vector<vector<vector<int>>> memo;

    int solve(int m, int n, int maxMove, int currRow, int currCol) {
        if (maxMove < 0) return 0;
        if (currRow >= m || currRow < 0 || currCol < 0 || currCol >= n) {
            return 1;
        }
        if (memo[maxMove][currRow][currCol] != -1) {
            return memo[maxMove][currRow][currCol];
        }

        long long paths = 0;
        paths += solve(m, n, maxMove - 1, currRow + 1, currCol) % MOD;
        paths += solve(m, n, maxMove - 1, currRow - 1, currCol) % MOD;
        paths += solve(m, n, maxMove - 1, currRow, currCol + 1) % MOD;
        paths += solve(m, n, maxMove - 1, currRow, currCol - 1) % MOD;

        memo[maxMove][currRow][currCol] = paths % MOD;
        return memo[maxMove][currRow][currCol];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo.assign(maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};

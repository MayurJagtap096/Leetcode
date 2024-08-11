class Solution {
public:

    bool allUnique(vector<vector<int>> &grid, int sr, int sc) {
        int arr[10] = {0};  // Array to count occurrences of numbers 1 to 9
        for(int i = sr; i < sr + 3; i++) {
            for(int j = sc; j < sc + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || arr[num] == 1) { // Check if number is out of range or not unique
                    return false;
                }
                arr[num] = 1;
            }
        }
        return true;
    }

    bool allRowSum(vector<vector<int>> &grid, int sr, int sc) {
        int sum = 0;
        for(int i = sr; i < sr + 3; i++) {
            int curr = 0;
            for(int j = sc; j < sc + 3; j++) {
                curr += grid[i][j];
            }
            if (sum == 0) {
                sum = curr;
            } else if (sum != curr) {
                return false;
            }
        }
        return true;
    }

    bool allColSum(vector<vector<int>> &grid, int sr, int sc) {
        int sum = 0;
        for(int j = sc; j < sc + 3; j++) {
            int curr = 0;
            for(int i = sr; i < sr + 3; i++) {
                curr += grid[i][j];
            }
            if (sum == 0) {
                sum = curr;
            } else if (sum != curr) {
                return false;
            }
        }
        return true;
    }

    bool allDiagonalSum(vector<vector<int>> &grid, int sr, int sc) {
        int leftsum = 0, rightsum = 0;
        for(int i = 0; i < 3; i++) {
            leftsum += grid[sr + i][sc + i];
            rightsum += grid[sr + i][sc + 2 - i];
        }
        return leftsum == rightsum;
    }

    bool solve(vector<vector<int>> &grid, int i, int j) {
        return allUnique(grid, i, j) && allRowSum(grid, i, j) && allColSum(grid, i, j) && allDiagonalSum(grid, i, j);
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() < 3 || grid[0].size() < 3) {
            return ans;
        }
        for(int i = 0; i <= grid.size() - 3; i++) {
            for(int j = 0; j <= grid[0].size() - 3; j++) {
                if(solve(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};
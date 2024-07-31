class Solution {
public:
    int WIDTH;
    int n;
    int mem[1001][1001];

    int solve(vector<vector<int>>& books, int remainingWidth, int i, int height) {
        if(i>=n) return height;

        int keep = INT_MAX;
        int skip = INT_MAX;

        if(mem[i][remainingWidth]!=-1) return mem[i][remainingWidth];
        
        //keep
        if(books[i][0] <= remainingWidth) {
            keep = solve(books, remainingWidth - books[i][0], i+1, max(height, books[i][1]));
        }

        //skip
        skip = height + solve(books, WIDTH - books[i][0], i+1, books[i][1]);

        return mem[i][remainingWidth] = min(skip, keep);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        WIDTH = shelfWidth;
        n = books.size();
        memset(mem,-1,sizeof(mem));
        return solve(books, shelfWidth, 0, 0);
    }
};
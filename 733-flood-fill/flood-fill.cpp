class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc, int color, int oldColor) {
        int rows = image.size();
        int cols = image[0].size();

        if (sr < 0 || sc < 0 || sr >= rows || sc >= cols || image[sr][sc] != oldColor || image[sr][sc] == color) {
            return;
        }

        image[sr][sc] = color;

        solve(image, sr + 1, sc, color, oldColor);
        solve(image, sr - 1, sc, color, oldColor);
        solve(image, sr, sc + 1, color, oldColor);
        solve(image, sr, sc - 1, color, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        if (rows == 0) return image; // Empty image case
        int cols = image[0].size();
        
        int oldColor = image[sr][sc];

        if (oldColor == newColor) return image; // No need to fill if newColor is same as oldColor
        
        solve(image, sr, sc, newColor, oldColor);
        
        return image;
    }
};

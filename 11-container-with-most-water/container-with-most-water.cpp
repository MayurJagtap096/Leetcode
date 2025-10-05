class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN;
        int i = 0;
        int j = height.size() - 1;
        while(i < j) {
            int cal = min(height[i], height[j]) * (j - i);
            area = max(cal, area);
            height[i] < height[j] ? i++ : j--;
        }
        return area;
    }
};
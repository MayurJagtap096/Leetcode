class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=0;
        int n=heights.size();
        int nse;
        int pse;
        int ele;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                ele=st.top();
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                maxArea=max(maxArea, heights[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            ele=st.top();
            st.pop();
            pse=st.empty()?-1:st.top();
            maxArea=max(maxArea, heights[ele]*(nse-pse-1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(r == 0) return 0;
        int c = matrix[0].size();

        vector<int> ps(c,0);
        int maxi = 0;

        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(matrix[i][j] == '1') ps[j]++;
                if(matrix[i][j] == '0') ps[j] = 0;
            }
            maxi = max(maxi, largestRectangleArea(ps));
        }
        return maxi;
    }
};
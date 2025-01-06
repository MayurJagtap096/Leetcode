class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());

        int cumValue=0;
        int cumSum=0;

        for(int i=0;i<boxes.size();i++) {
            ans[i] = cumSum;
            cumValue += boxes[i]=='1' ? 1:0;
            cumSum += cumValue;
        }
        cumValue=0;
        cumSum=0;
        for(int i=boxes.size()-1;i>=0;i--) {
            ans[i] += cumSum;
            cumValue += boxes[i]=='1' ? 1:0;
            cumSum += cumValue;
        }
        return ans;
    }
};
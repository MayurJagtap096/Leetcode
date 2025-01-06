class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        vector<int> indices;
        for(int i=0;i<boxes.size();i++) {
            if(boxes[i]=='1') indices.push_back(i);
        }
        for(int i=0;i<boxes.size();i++) {
            int temp=0;
            for(int index: indices) {
                temp += abs(index-i);
            }
            ans[i] = temp;
        }
        return ans;   
    }
};
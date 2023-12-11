class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int s = arr.size();
        s = s/4;
        int p = arr[0];
        int c=1;
        for(int i=1;i<arr.size();i++){
            if(p==arr[i]) c++;
            else c=1;
            if(c>s) return arr[i];
            p = arr[i];
        }
        return p;
    }
};
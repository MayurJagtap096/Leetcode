class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int s = arr.size();
        s = s/4;
        unordered_map<int,int> m;
        for(int a:arr) m[a]++;
        for(auto a:m){
            if(a.second > s) return a.first;
        }
        return -1;
    }
};
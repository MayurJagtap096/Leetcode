class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++) {
            m[arr[i]]++;
        }
        vector<int> v;
        for(auto a:m) {
            v.push_back(a.second);
        }
        for(auto a:m) {
            int count=0;
            for(int i=0;i<v.size();i++) {
                if(v[i]==a.second) {
                    count++;
                }
            }
            if(count>1) return false;
        }
        return true;
    }
};
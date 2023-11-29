class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int a:nums) m[a]++;
        for(auto a:m){
            if(a.second==1) return a.first;
        }
        return -1;
    }
};
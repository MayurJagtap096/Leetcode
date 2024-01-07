class Solution {
public:
    vector<int> v;
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    int pick(int target) {
        int len = v.size();
        int random = rand()%len;
        while(v[random]!=target) {
            random = rand()%len;
        }
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
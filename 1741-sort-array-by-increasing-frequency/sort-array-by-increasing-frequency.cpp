class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int freq[201] = {0};
        for(int i:nums) {
            freq[i+100]++;
        }
        sort(nums.begin(), nums.end(),[&](int x, int y){
            return freq[x+100]==freq[y+100] ? x>y : freq[x+100] < freq[y+100]; 
        });
        return nums;
    }
};
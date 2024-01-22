class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int first = 0;
        int second =0 ; 
        vector<int> count(nums.size()+1, 0);
        count[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            count[nums[i]]++;
        }
        for(int j =1;j<count.size();j++){
            if(count[j] >1) first =j;
            if(count[j] == 0) second =j;
        }
        return {first,second};
    }
};
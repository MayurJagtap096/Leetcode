class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int k=0;k<=31;k++){
            int temp = (1<<k);
            int ones=0;
            for(int &num:nums){
                if((num & temp)!=0) ones++;
            }
            if(ones % 3 == 1) ans = (ans | temp);
        }
        return ans;
    }
};
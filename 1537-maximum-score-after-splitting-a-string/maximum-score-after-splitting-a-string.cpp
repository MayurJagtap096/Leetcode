class Solution {
public:
    int maxScore(string s) {
        int left = 0;
        int right = count(s.begin(),s.end(),'1');
        int ans = 0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0') left++;
            if(s[i]=='1') right--;
            ans = max(ans,left+right);
        }
        return ans;
    }
};
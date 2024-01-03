class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0,curr=0,ans=0;
        for(int i=0;i<bank.size();i++){
            curr = count(bank[i].begin(),bank[i].end(),'1');
            ans += curr*prev;
            if(curr!=0) prev=curr;
        }
        return ans;
    }
};
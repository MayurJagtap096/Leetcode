class Solution {
public:
    int minOperations(string s) {
        int x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0 && s[i]=='0'){
                x++;
            }
            if(i%2==1 && s[i]=='1'){
                x++;
            }
            if(i%2==0 && s[i]=='1'){
                y++;
            }
            if(i%2==1 && s[i]=='0'){
                y++;
            }
        }
        return min(x,y);
    }
};
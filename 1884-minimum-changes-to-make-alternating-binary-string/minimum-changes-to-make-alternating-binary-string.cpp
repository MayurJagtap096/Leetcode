class Solution {
public:
    int minOperations(string s) {
        int count = 0, expected = 0;
        for(int i=0;i<s.length();i++) {
            if(!((s[i]-'0') == expected)) count++;
            expected ^= 1; 
        }
        return min(count, (int)s.size()-count);
    }
};
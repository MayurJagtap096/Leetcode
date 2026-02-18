class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n==0) return true;
        string s = bitset<32>(n).to_string();
        s = s.substr(s.find('1'));
        for(int i=1;i<s.size();i++) {
            if(s[i]==s[i-1]) return false;
        }
        return true;
    }
};
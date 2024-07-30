class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count=0;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(!st.empty() && s[i] == 'a' && st.top() == 'b') {
                st.pop();
                count++;
            }
            else {
                st.push(s[i]);
            }
        }
        return count;
    }
};
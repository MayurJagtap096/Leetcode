class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int a=0;
        for(char c: s) {
            if(c == '(') {
                st.push(c);
            }
            else {
                if(st.empty()) {
                    a++;
                }
                else st.pop();
            }
        }
        return a+st.size();
    }
};
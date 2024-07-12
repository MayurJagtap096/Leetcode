class Solution {
public:

    string removeSubstr(string &s, string &str) {
        stack<char> st;

        for(char &ch: s) {
            if(ch == str[1] && !st.empty() && st.top() == str[0]){
                st.pop();
            } 
            else {
                st.push(ch);
            }
        }

        string temp;
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;

        string maxStr = x > y ? "ab" : "ba";
        string minStr = x < y ? "ab" : "ba";

        // firstly we have to calculate points for maxStr to get maximum points
        string firstTraverse = removeSubstr(s, maxStr);

        int removedCharacters = s.length() - firstTraverse.length();
        ans += (removedCharacters / 2) * max(x,y);

        string secondTraverse = removeSubstr(firstTraverse,minStr);

        removedCharacters = firstTraverse.length() - secondTraverse.length();
        ans += (removedCharacters / 2) * min(x,y);

        return ans;

    }
};
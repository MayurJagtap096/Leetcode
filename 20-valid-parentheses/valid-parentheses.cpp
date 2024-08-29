class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        for(char &ch:s)
        {
            if(ch=='(')
               st.push(')');
            else if(ch=='{')
               st.push('}');
            else if(ch=='[')
               st.push(']');
            else
            {
                if(st.empty() || ch!=st.top())
                   return false;
                else
                   st.pop();
            }
        }
        return st.empty();
    }
};
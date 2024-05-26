class Solution {
public:

    bool isPalindrome(string &s, int l, int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(string& s, int index, vector<vector<string>> &ans, vector<string> temp)
    {
        if(index==s.length())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<s.length();i++)
        {
            if(isPalindrome(s,index,i))
            {
                temp.push_back(s.substr(index, i-index+1));
                backtrack(s, i+1, ans, temp);
                temp.pop_back();
            }   
        }
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(s,0,ans,temp);

        return ans;    
    }
};
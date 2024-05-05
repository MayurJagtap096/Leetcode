class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        int fo=-1;
        for(int i=0;i<word.length();i++)
        {
            if(word[i] == ch)
            {
                fo = i;
                break;
            }
        }
        if(fo==-1) return word;
        int temp = fo;
        for(int i=0;i<=fo/2;i++)
        {
            swap(word[i],word[temp--]);
        }
        return word;
    }
};
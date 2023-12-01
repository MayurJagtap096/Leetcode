class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first="",second="";
        for(string a: word1) first+=a;
        for(string a: word2) second+=a;
        if(first==second) return true;
        return false;
    }
};
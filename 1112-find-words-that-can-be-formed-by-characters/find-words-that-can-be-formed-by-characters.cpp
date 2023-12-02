class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        unordered_map<char,int> m;
        for(char a:chars) m[a]++;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int> temp = m;
            bool flag = true;
            for(char c:words[i]){
                if(temp[c]==0)flag = false;
                else temp[c]--;
            }
            if(flag==true) ans+=words[i].length();
        }
        return ans;
    }
};
class Solution {
public:
    bool solve(string a,string b){
        int i=0,j=0;
        while(i<a.length() && j<b.length()){
            if(a[i]==b[j]){
                i++;
            }
            j++;
        }
        return i==a.length();
    }
    int findLUSlength(vector<string>& strs) {
        int maxi=-1;
        for(int i=0;i<strs.size();i++){
            bool flag=true;
            for(int j=0;j<strs.size();j++){
                
                if(i!=j && solve(strs[i],strs[j])){
                   flag=false;
                   break;
                }
            }
            if(flag){
                    int x=strs[i].length();
                    maxi=max(maxi,x);
                }
        }
        return maxi;
    }
};
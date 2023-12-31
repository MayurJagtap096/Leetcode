class Solution {
public:
    
    bool checkOverlap(vector<int>& selected,string currString){
        // check duplicates in current string to be selected
        vector<int> check(26,0);
        
        for(int i = 0; i < currString.length();i++){
            if(check[currString[i]-'a'] == 1) return true;
            check[currString[i]-'a'] = 1;
        }
        
        // check if some char in curr string existed in previously selected string
        for(int i = 0; i < currString.length();i++){
            if(selected[currString[i]-'a'] == 1) return true;
        }
        
        return false;
    }
    
    int helper(vector<string> &arr,vector<int> &selected,int idx,int len){
        if(idx >= arr.size()){
            return len;
        }
        
        string curr = arr[idx];
        
        // if overlap don't take curr
        if(checkOverlap(selected,curr) == true){
            return helper(arr,selected,idx+1,len);
        }
        
        // if no overlap we have two choices take / not take curr
        else{
            
            //marking curr char in selected
            for(int i = 0; i < curr.length();i++){
                selected[curr[i]-'a'] = 1;
            }
            
            int take = helper(arr,selected,idx+1,len + curr.length());
            
            //backtrack
            for(int i = 0; i < curr.length();i++){
                selected[curr[i]-'a']  = 0;
            }
            
            int nottake = helper(arr,selected,idx+1,len);
            
            return max(take,nottake);
        }
        
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
        return helper(arr,selected,0,0); 
    }
};
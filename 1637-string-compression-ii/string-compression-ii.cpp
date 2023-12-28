int dp[101][27][101][101] ; 
class Solution {
public:

    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size() ;

        // get prev as a character input. to reduce prev.
        // treated 26 as -1.

        // return solve(s, 0, 26, k, 0) ; 
        memset(dp , -1, sizeof(dp)) ;
        return solveMem(s, 0, 26, k, 0) ;

    }
private:
// Recursion
    int solve(string& s, int index,int prev, int k, int count){
        if(k < 0) return 1e9 ;

        if(index >= s.size()){
           return 0 ;
        }

        int acc = INT_MAX ;
        int del = INT_MAX ; 

        
        del = solve(s, index+1, prev, k-1, count) ; 

        if(prev + 'a' == s[index]){
            if(count == 1 || count == 9 || count == 99){
                acc =  1 + solve(s, index+1, prev, k, count+1) ; 
            }
            else{
                acc =  solve(s, index+1, prev, k, count+1) ; 
            }
        }
        else{
            acc =  1 + solve(s, index+1, s[index] - 'a', k, 1) ; 
        }
        
        return min(del, acc) ;
    }
// Memorisation
    int solveMem(string& s, int index, int prev, int k, int count){
        if(k < 0) return 1e9 ;

        if(index >= s.size()){
           return 0 ;
        }

        if(dp[index][prev][k][count] != -1){
            return dp[index][prev][k][count] ;
        }

        int acc = INT_MAX ;
        int del = solveMem(s, index+1, prev, k-1, count) ; 

        if(prev + 'a' == s[index]){
            if(count == 1 || count == 9 || count == 99){
                acc =  1 + solveMem(s, index+1, prev, k, count+1) ; 
            }
            else{
                acc =  solveMem(s, index+1, prev, k, count+1) ; 
            }
        }
        else{
            acc =  1 + solveMem(s, index+1, s[index] - 'a', k, 1) ; 
        }

        
        return dp[index][prev][k][count] = min(del, acc) ;
    }
};
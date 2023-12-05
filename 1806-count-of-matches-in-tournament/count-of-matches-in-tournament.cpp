class Solution {
public:
    int solve(int n){
        if(n==1) return 0;
        if(n%2==0) return n/2 + solve(n/2);
        return (n-1)/2 + solve((n-1)/2+1);
    }
    int numberOfMatches(int n) {
        return solve(n);
    }
};
class Solution {
public:
    bool isPerfectSquare(int num) {
        int s=1, e=num ;
        long long int mid = s + (e-s)/2 ;
        while (s <= e){
            if (num == mid*mid) return true ;
            if (num > mid*mid) s = mid+1 ;
            else e = mid-1 ;
            mid = s + (e-s)/2 ;
        }
        return false ;
    }
};
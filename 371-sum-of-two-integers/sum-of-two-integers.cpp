class Solution {
public:
    int getSum(int a, int b) {   
        if(b==0) return a;
        if(b<0) return getSum(--a,++b);
        else return getSum(++a,--b);
    }
};
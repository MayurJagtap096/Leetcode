class Solution {
public:
    int nthUglyNumber(int n) {
        int i2=1, i3=1, i5=1;
        vector<int> v(n+1);
        v[1] = 1;
        for(int i=2;i<=n;i++) {
            int i2UglyNumber = v[i2]*2;
            int i3UglyNumber = v[i3]*3;
            int i5UglyNumber = v[i5]*5;
            int uglyNumber = min({i2UglyNumber,i3UglyNumber,i5UglyNumber});
            v[i] = uglyNumber;
            if(uglyNumber == i2UglyNumber) i2++;
            if(uglyNumber == i3UglyNumber) i3++;
            if(uglyNumber == i5UglyNumber) i5++;
        }
        return v[n];
    }
};
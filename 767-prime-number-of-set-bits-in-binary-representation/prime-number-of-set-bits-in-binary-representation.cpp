class Solution {
public:

    int get_count_of_ones(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='1') ans++;
        }
        return ans;
    }

    bool isPrime(int n) {
        if(n==1) return false;
        for(int i=2;i<n;i++) {
            if(n%i==0) return false;
        }
        cout<<n<<endl;
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++) {
            string s = bitset<32>(i).to_string();
            int count = get_count_of_ones(s);
            ans += 1 ? isPrime(count) : 0;
        }
        return ans;
    }
};
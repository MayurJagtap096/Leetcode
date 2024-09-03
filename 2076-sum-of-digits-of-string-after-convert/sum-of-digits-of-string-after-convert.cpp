class Solution {
public:
    int getLucky(string s, int k) 
    {
        string num;
        for(char c: s)
        {
            int n = c - 'a' + 1;
            num += to_string(n);
        }
        while(k>0)
        {
            int temp = 0;
            for(char c: num)
            {
                temp += c - '0';
            }
            num = to_string(temp);
            k--; 
        }
        return stoi(num);
    }
};

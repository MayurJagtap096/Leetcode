class Solution {
public:

    int findDigitToMaximise(string toMaximise) {
        for(int i=0;i<toMaximise.length();i++) {
            if(toMaximise[i] != '9') {
                return toMaximise[i] - '0';
            }
        }
        return -1;
    }

    int maxDiff(int num) {
        string toMaximise = to_string(num);
        string toMinimise = to_string(num);

        int n = findDigitToMaximise(toMaximise);
        if(n != -1) {
            for(int i=0;i<toMaximise.length();i++) {
                if((toMaximise[i] - '0') == n) {
                    toMaximise[i] = '9';
                }
            }
        }
        char c = toMinimise[0];
        char replace = '1';

        if(c == '1') {
            for(int i=1;i<toMinimise.length();i++) {
                if(toMinimise[i] != '0' && toMinimise[i] != '1') {
                    c = toMinimise[i];
                    replace = '0';
                    break;
                }
            }
        }
        
        for(int i=0;i<toMinimise.length();i++) {
            if(toMinimise[i] == c) toMinimise[i] = replace;
        }
        return stoi(toMaximise) - stoi(toMinimise);
    }
};
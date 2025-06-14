class Solution {
public:

    int findDigitToReplace(string str) {
        for(int i=0;i<str.length();i++) {
            if(str[i] != '9') {
                return str[i] - '0';
            }
        }
        return -1;
    }

    int minMaxDifference(int num) {
        string maxstr = to_string(num);
        string minstr = to_string(num);

        int n = findDigitToReplace(maxstr);

        for(int i=0;i<minstr.length();i++) {
            if((minstr[i]) == maxstr[0]) {
                minstr[i] = '0';
            }
        }
        
        for(int i=0;i<maxstr.length();i++) {
            if((maxstr[i] - '0') == n) {
                maxstr[i] = '9';
            }
        }

        return stoi(maxstr) - stoi(minstr);
    }
}; 
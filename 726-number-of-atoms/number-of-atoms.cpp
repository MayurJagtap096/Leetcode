class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i = 0;
        
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;
                string num;
                while (i < n && isdigit(formula[i])) {
                    num.push_back(formula[i]);
                    i++;
                }
                int intNum = num.empty() ? 1 : stoi(num);
                for (auto& it : curr) {
                    string element = it.first;
                    int count = it.second;
                    curr[element] = count * intNum;
                }
                for (auto& it : curr) {
                    string element = it.first;
                    int count = it.second;
                    st.top()[element] += count;
                }
            } else {
                string currElement;
                currElement.push_back(formula[i]);
                i++;
                while (i < n && isalpha(formula[i]) && islower(formula[i])) {
                    currElement.push_back(formula[i]);
                    i++;
                }
                string currCount;
                while (i < n && isdigit(formula[i])) {
                    currCount.push_back(formula[i]);
                    i++;
                }
                int currCountInt = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currElement] += currCountInt;
            }
        }
        
        string ans = "";
        map<string, int> sortedMap(st.top().begin(), st.top().end());
        for (auto& it : sortedMap) {
            string element = it.first;
            int count = it.second;
            ans += element;
            if (count > 1) ans += to_string(count);
        }
        return ans;
    }
};
class Solution {
public:
    bool checkValidString(string s) {
         stack<int> St;
        stack<int> St1;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                St.push(i);
            } else if (ch == '*') {
                St1.push(i);
            } else {
                if (!St.empty()) {
                    St.pop();
                } else if (!St1.empty()) {
                    St1.pop();
                } else {
                    return false;
                }
            }
        }

       
        while (!St.empty() && !St1.empty()) {
            if (St.top() > St1.top()) {
                return false;
            }
            St.pop();
            St1.pop();
        }

        return St.empty();
       
    }
};
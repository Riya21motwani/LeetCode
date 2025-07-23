class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, bool> visited;
        
        for (char c : s) freq[c]++;

        stack<char> st;

        for (char c : s) {
            freq[c]--; 

            if (visited[c]) continue; 

            while (!st.empty() && c < st.top() && freq[st.top()] > 0) {
                visited[st.top()] = false;
                st.pop();
            }

            st.push(c);
            visited[c] = true;
        }

       
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()!=s[i] ||  st.empty()){
                st.push(s[i]);
                continue;
            }
            while(!st.empty() && st.top()==s[i]){
                st.pop();
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }

        return ans;
    }
};
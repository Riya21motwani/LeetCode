class Solution {
public:
    string minRemoveToMakeValid(string s) {
       int n = s.length();
        
        unordered_set<int> uset;
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') 
                st.push(i);
            else  if(s[i] == ')') {
                if(st.empty()) { 
                    uset.insert(i);
                } else {
                    st.pop();
                }
            }
        }
        while(!st.empty()){
           uset.insert(st.top());
            st.pop();
        }
        
        string res="";
        for(int i=0;i<n;i++){
            
            
            if(uset.find(i)==uset.end()){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
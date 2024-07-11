class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<int>st;
        for(auto it:s){
            if(it=='('){
                st.push(')');
            }
            else if(it=='{'){
                st.push('}');
            }
            else if(it=='['){
                st.push(']');
            }
            else if(st.empty() || it!=st.top()){
                return false;
            }else{
                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};
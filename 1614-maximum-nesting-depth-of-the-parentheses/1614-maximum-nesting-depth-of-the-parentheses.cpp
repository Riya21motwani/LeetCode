class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int res=0;
        stack<int>st;
        for(int i=0;i<n;i++){
       
            if(s[i]=='('){
           st.push(s[i]);
                int t=st.size();
                res=max(res,t);

            }
            else if(s[i]==')'){
                     st.pop();
            }

        }
        return res;
    }
};
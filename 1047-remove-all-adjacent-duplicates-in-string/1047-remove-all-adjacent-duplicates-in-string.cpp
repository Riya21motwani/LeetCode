class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string ans="";
        int n=s.size();
      for(int i=n-1;i>=0;i--){
       if(st.empty()){
        st.push(s[i]);
       }
        else{
            if(st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
      }


        while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
        }
        return  ans;
    }
};
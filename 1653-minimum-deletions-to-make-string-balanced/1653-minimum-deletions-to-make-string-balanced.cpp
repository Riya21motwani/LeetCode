class Solution {
public:
    int minimumDeletions(string s) {
       stack<char>st;
       int n=s.size();
       int cnt=0;
       
       for(int i=0;i<n;i++){
        if(!st.empty() && st.top()=='b' && s[i]=='a'){
            cnt++;
            st.pop();
        }else{
            st.push(s[i]);
        }
       }

        
       
       return cnt;
    }

};
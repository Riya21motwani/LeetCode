class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        stack<int>st;
        int num=0;
        int res=0;
        int sign=1;
        
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                res=res+num*sign;
                num=0;
                sign=1;
            }
            else if(s[i]=='-'){
                res=res+num*sign;
                num=0;
              
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                num=0;
                res=0;
                sign=1;
            }
            else if(s[i]==')'){
                res+=num*sign;
                int stack_sign=st.top();
                st.pop();
                int stack_no=st.top();
                st.pop();
                res=res*stack_sign;
                res+=stack_no;
                num=0;
            }
        }
          res+=num*sign;
         return res;
    }
};
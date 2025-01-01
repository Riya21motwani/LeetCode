class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        int n=path.size();
        stack<string>st;
        int i=0;

        while(i<n){
            if(path[i]=='/'){
                i++;
                continue;
            }
            string temp="";
            while(i < path.size() && path[i]!='/'){
            temp=temp+path[i];
            i++;
            } 
            if(temp=="."){
                continue;
            }
            
            if(!st.empty()&& temp==".."){
                st.pop();
            }
            else if(st.empty() && temp==".."){
                continue;
            }
            
            else{
                st.push(temp);
            }
            
        }
        while(!st.empty()){
            ans='/'+st.top()+ans;
            st.pop();
        }
        int n1=ans.size();
        if(n1!=0 && ans[n1-1]=='/'){
            ans.pop_back();
        }

        if(ans==""){
            return "/";
        }

        return ans;
    }
};
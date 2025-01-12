class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2==1){
            return false;
        }

        stack<char>sto;
        stack<char>stoc;

        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                stoc.push(i);
            }
            else{

                if(s[i]==')'){
                    if(!sto.empty()){
                        sto.pop();
                    }
                    else if(!stoc.empty()){
                        stoc.pop();
                    }else{
                        return false;
                    }
                }
                else if(s[i]=='('){
                    sto.push(i);
                }
            }
        }

        while(!sto.empty() && !stoc.empty() && sto.top()<stoc.top()){
            sto.pop();
            stoc.pop();
        }

        if(sto.empty() && stoc.size()%2==0){
            return true;
        }

        return false;


    }
};
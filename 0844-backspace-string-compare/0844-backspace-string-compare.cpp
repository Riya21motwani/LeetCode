class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        string temp1="";
        string temp2="";

        for(int i=0;i<n1;i++){
            if(temp1.size()>0 && s[i]=='#'){
               temp1.pop_back();
            }
            else if(temp1.size()==0 && s[i]=='#'){
                continue;
            }
            else if(s[i]!='#'){
                temp1.push_back(s[i]);
                
            }
        }

        for(int i=0;i<n2;i++){
            if(temp2.size()>0 && t[i]=='#'){
               temp2.pop_back();
            }
            else if(temp2.size()==0 && t[i]=='#'){
                continue;
            }
            else if(t[i]!='#'){
                temp2.push_back(t[i]);
                
            }
        }

        return temp1==temp2;
    }
};
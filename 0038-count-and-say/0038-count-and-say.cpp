class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string find=countAndSay(n-1);
        string res="";
        for(int i=0; i<find.size();i++){
            char ch=find[i];
            int cnt=1;
            
            while(i<find.size()-1 && find[i]==find[i+1]){
                cnt++;
                i++;
            }
            
            res+=to_string(cnt)+string(1,ch);
        }
        
        return res;
    }
};
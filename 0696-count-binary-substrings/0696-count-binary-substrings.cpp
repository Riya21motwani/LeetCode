class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int p=0;
        int c=1;
        int ans=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                ans+=min(p,c);
                p=c;
                c=1;
            }else{
                c+=1;
            }
        }
        ans+=min(p,c);
        return ans;
    }
};
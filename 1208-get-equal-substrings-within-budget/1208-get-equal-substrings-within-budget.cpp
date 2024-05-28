class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cnt=0;
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        int length=0;
        while(j<s.size()){
            cnt+=abs(s[j]-t[j]);
             if(cnt>maxCost){
                 cnt-=abs(s[i]-t[i]);
                 i++;
             }
            length=j-i+1;
            maxi=max(maxi,length);
            j++;
            
        }
        return maxi;
    }
};
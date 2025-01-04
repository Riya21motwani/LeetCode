class Solution {
public:

    int countPalindromicSubsequence(string s) {
        int n=s.size();
        int ans=0;
        unordered_set<char>uset;
        for(int i=0;i<n;i++){
            uset.insert(s[i]);
        }

        for(auto it:uset){
            int ind1=-1;
            int ind2=-1;
            int el=it;
            for(int i=0;i<n;i++){
                if(el==s[i]){
                    if(ind1==-1){
                        ind1=i;
                    }
                    ind2=i;
                }
            }
            unordered_set<char>st;
            for(int i=ind1+1;i<=ind2-1;i++){
                st.insert(s[i]);
            }
            ans+=st.size();
        }
        return ans;
    }
};
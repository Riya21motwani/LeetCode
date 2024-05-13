class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>arr(26);
        for(int i=0;i<s.size();i++){
            int ind=s[i]-'a';
            arr[ind]=i;
        }
        int diff=0;
        for(int i=0;i<t.size();i++){
             int ind1=t[i]-'a';
             diff+=abs(arr[ind1]-i);
        }
        return diff;
    }
};
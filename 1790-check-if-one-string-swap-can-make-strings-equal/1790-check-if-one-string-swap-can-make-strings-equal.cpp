class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;
        int n1=s1.size();
        int n2=s2.size();
        unordered_set<char>uset;
        if(n1!=n2){
            return true;
        }
        for(int i=0;i<n1;i++){
            if(s1[i]!=s2[i]){
                cnt++;
                uset.insert(s1[i]);
                 uset.insert(s2[i]);
            }
        }

        if(cnt==0 && uset.size()<=2 || cnt==2 && uset.size()<=2){
            return true;
        }
        return false;
    }
};
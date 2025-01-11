class Solution {
public:

   

    bool canConstruct(string s, int k) {
        
        if(k>s.size()){
            return false;
        }
        if(k==s.size()){
            return true;
        }
        int cnt1=0;
        unordered_map<char,int>umap;
        int n=s.size();
        for(int i=0;i<n;i++){
            umap[s[i]]++;
        }

        for(auto it:umap){
            if(it.second%2==1){
                cnt1++;
            }
        }
        if(cnt1>k){
            return false;
        }
     
     return true;
    }
};
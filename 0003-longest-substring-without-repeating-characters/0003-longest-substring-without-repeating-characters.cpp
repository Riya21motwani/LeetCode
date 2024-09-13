class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        
        unordered_map<char,int>umap;
        int i=0;
        int j=0;
        
        int maxcnt=0;
        while(j<n){
            if(umap.find(s[j]) != umap.end() && i <= umap[s[j]]){
                i=umap[s[j]]+1;
                
            }
            else{
                maxcnt=max(maxcnt,j-i+1);
            }
            
            umap[s[j]]=j;
            
            j++;
        }
       
        
        return maxcnt;
    }
};
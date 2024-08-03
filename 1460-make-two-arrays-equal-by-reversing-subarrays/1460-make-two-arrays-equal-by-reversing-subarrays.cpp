class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       
        int n=target.size();
        unordered_map<int,int>umap1;
        unordered_map<int,int>umap2;
        
        for(int i=0;i<n;i++){
            umap1[target[i]]++;
            umap2[arr[i]]++;
        }
        
        for(auto it:umap1){
           int element=it.first;
            
            int freq=it.second;
            
            if(umap2.find(element)==umap2.end()){
             return false;
            }
            else if(umap2.find(element)!=umap2.end() && umap2[element]!=freq){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    
   
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int>umap;
        vector<int>ans;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
              if(x==nums[i]){
                  
                    umap[cnt]=i;
                  cnt++;
              }
        }
        
        
       for(int i=0;i<queries.size();i++){
             if(umap.find(queries[i])!=umap.end()){
                   queries[i]=umap[queries[i]];
             }else{
                   queries[i]=-1;
             }
       }
    
        
      return queries;
    }
};
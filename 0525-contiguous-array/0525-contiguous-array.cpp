class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int curs=0;
        unordered_map<int,int>umap;
        umap[curs]=-1;
        int maxi=0;
       
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                curs+=1;
            }else{
              curs+=-1;
            }
            
            
            if(umap.find(curs)!=umap.end()){
              maxi=max(maxi,i-umap[curs]);
            }else{
                umap[curs] =i;
            }
        }
        return maxi;
    }
};
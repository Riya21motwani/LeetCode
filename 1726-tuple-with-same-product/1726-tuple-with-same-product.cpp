class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i){
                int mul=nums[i]*nums[j];
                umap[mul]+=1;
            }
        }

        }
        int total=0;
        for(auto it:umap){
            if(it.second==4){
                total+=8;
            }
        }
        return total;
    }
};
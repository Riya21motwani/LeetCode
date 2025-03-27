class Solution {
public:

    int f(int s, int e, vector<int>& nums){
        unordered_map<int,int>umap;

        for(int i=s;i<=e;i++){
            umap[nums[i]]++;

        }
        int maxi=-1;
        int freq=-1;

        for(auto it:umap){
            if(it.second>freq){
                maxi=it.first;
                freq=it.second;
            }
        }
        int m=e-s+1; 

        if(freq> m/2){
            return maxi;
        }


        return -1;
    }



    int minimumIndex(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int el1=f(0,i,nums);
            int el2=f(i+1,n-1 , nums);

            if(el1==el2 && el1!=-1){
                return i;
            }
            
            
        }

        return -1;
    }
};
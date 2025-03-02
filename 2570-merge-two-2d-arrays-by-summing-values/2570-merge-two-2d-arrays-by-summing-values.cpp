class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
     vector<vector<int>> ans;
     unordered_map<int,int>umap;
     int maxi=0;
     for(int i=0;i<nums1.size();i++)   {
        int u=nums1[i][0];
        int v=nums1[i][1];
        if(umap.find(u)==umap.end()){
            umap[u]=v;
        }else{
            umap[u]=umap[u]+v;
        }
        maxi=max(maxi,u);
     }


     for(int i=0;i<nums2.size();i++)   {
        int u=nums2[i][0];
        int v=nums2[i][1];
        if(umap.find(u)==umap.end()){
            umap[u]=v;
        }else{
            umap[u]=umap[u]+v;
        }
        maxi=max(maxi,u);
     }

     for(int i=1;i<=maxi;i++){
        if(umap.find(i)!=umap.end()){
            ans.push_back({i,umap[i]});
            
        }
     }

return ans;


    }
};
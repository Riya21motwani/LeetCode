class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string , int >umap;
        int n=arr.size();
        for(int i=0;i<n;i++){
            umap[arr[i]]++;
        }
        vector<string>v;
        for(auto it:umap){
            int freq=it.second;
            if(freq==1){
                v.push_back(it.first);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<v.size();j++){
                if(arr[i]==v[j]){
                    k--;
                    if(k==0){
                        return arr[i];
                    }
                }
            }
        }
        return "";
    }
};
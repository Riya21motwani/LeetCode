class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>newa(n);
       unordered_map<int,int>umap;
        
        for(int i=0;i<n;i++){
            int cnt=0;
           umap[A[i]]++;
           umap[B[i]]++;

           for(auto it:umap){
            if(it.second==2){
                cnt+=1;
            }
           }
           newa[i]=cnt;
            
        }

        return newa;
       
    }
};
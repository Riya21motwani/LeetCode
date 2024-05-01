class Solution {
public:
    unordered_map<int,int>umap;
        umap[0]=1;
        int doxor=0;
        long long ans=0;
        for(char & ch1:word){
  
            
            int t=ch1-'a';
            doxor^=(1<<t);
            ans+=umap[doxor];
            
            for(char ch2 ='a' ; ch2<='j';ch2++){
                 
                t=ch2-'a';
                long long checking =(doxor^(1<<t));
                ans+=umap[checking];
            }
        
         umap[doxor]++;
        }
        return ans;
    }
};

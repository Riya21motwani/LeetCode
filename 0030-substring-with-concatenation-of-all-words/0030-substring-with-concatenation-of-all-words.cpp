class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        unordered_map<string,int>umap;
        for(int i=0;i<words.size();i++){
            umap[words[i]]++;
        }
        
        int k=words.size();
        int m=words[0].size();
        vector<int>ans;
        int n=s.size();
        for(int i=0;i<m;i++){
            int l=i;
            int r=i;
             unordered_map<string,int>vis;
int cnt=0;
            while(r+m<=s.size()){
                string d=s.substr(r,m);
                r+=m;
                if(umap.find(d)!=umap.end()){
                    cnt+=1;
                    vis[d]++;
                    while(vis[d]>umap[d]){
                        cnt-=1;
                        string remove=s.substr(l,m);
                        vis[remove]--;
                        l+=m;
                    }
                    if(cnt==k){
                        ans.push_back(l);
                    }

                }
                
                else{
                    vis.clear();
                    cnt=0;
                    l=r;
                }
            
            }
        }

        return ans;
    }
};

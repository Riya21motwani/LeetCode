class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
         vector<int> ans;
        int cnt=0;
        unordered_map<char,int>umap;
          unordered_map<char,int>umap1;
        for(int i=0;i<n;i++){
            umap[s[i]]++;
        }
        int elremove=0;
        unordered_set<char>st;

        for(int i=0;i<n;i++){
            char ch=s[i];
            st.insert(ch);
            if(umap[ch]>0){
                umap[ch]--;
                if(umap[ch]==0){
                    elremove++;
                    umap.erase(ch);
                }
                cnt++;
            }
                if(st.size()==elremove){
                    ans.push_back(cnt);
                    cnt=0;
                    st.clear();
                    elremove=0;
                }
            
        }

        return ans;
    }
};
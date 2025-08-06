class Solution {
public:


    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x){
            return x;
        }

        return parent[x]=find(parent[x]);
    }

    void unionbyrank(int u , int v){
        int u_parent=find(u);
        int v_parent=find(v);
        if(u_parent==v_parent)return;

        if(rank[u_parent]<rank[v_parent]){
            parent[v_parent]=u_parent;
        }else  if(rank[v_parent]<rank[u_parent]){ 
            parent[u_parent]=v_parent;
        }else{
            parent[u_parent]=v_parent;
            rank[v_parent]++;
        }

    }


   
    bool f(string &s1,string&s2){
        if(s1.size()!=s2.size()){
            return false;
        }
        if(s1==s2)return true;
        int n=s1.size();
        vector<int>dif;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                dif.push_back(i);
            }
            if(dif.size()>2){
                return false;
            }
        }

        return (dif.size()==2 && s1[dif[0]]==s2[dif[1]] && s1[dif[1]]==s2[dif[0]]);
    }

    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
      
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               
                if(f(strs[i],strs[j])==true){
                    unionbyrank(i,j);
                }
            }
           
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                cnt++;
            }
        }

        return cnt;
    }
};
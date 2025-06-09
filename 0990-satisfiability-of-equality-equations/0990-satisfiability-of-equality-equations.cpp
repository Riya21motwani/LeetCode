class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    
    int findParent(int i ){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=findParent(parent[i]);
    }
    
    void unionbyrank(int u, int v){
        int u_parent=findParent(u);
        int v_parent=findParent(v);
        if(u_parent==v_parent){
            return;
        }
        if(rank[u_parent]>rank[v_parent]){
            parent[v_parent]=u_parent;
        }else if( rank[u_parent]<rank[v_parent]){
             parent[u_parent]=v_parent;
        }else{
            parent[u_parent]=v_parent;
            rank[v_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++){
            rank[i]=1;
            parent[i]=i;
        }

        for(string &it:equations){
            if(it[1]=='='){
                unionbyrank(it[0]-'a'  , it[3]-'a');
            }
        }
        for(string &it:equations){
            if(it[1]=='!'){
                if(findParent(parent[it[0]-'a'])==findParent(parent[it[3]-'a'])){
                    return false;
                }
            }
        }

        return true;
    }
};
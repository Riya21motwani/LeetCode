class Solution {
public:


    int bfs(int node, unordered_map<int,vector<int>>&adj, vector<bool>&visited ){
        queue<pair<int,int>>q;
        q.push({node,0});
        int maxi=0;
        while(!q.empty()){
            int currnode=q.front().first;
            int dist=q.front().second;
            q.pop();
            for(auto it:adj[currnode]){
                if(!visited[it]){
                visited[it]=true;
                q.push({it,dist+1});
                maxi=max(maxi,dist+1);
                }
            }
        }
        return maxi;
    }


    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++){
            int u=i;
            int v=favorite[i];
            adj[v].push_back(u);
        }
        int twolength=0;
        int longcycle=0;

        vector<bool>vis(n,false);

        for(int i=0;i<n;i++){

            if(!vis[i]){

                unordered_map<int,int>umap;
                int currnode=i;
                int cnt=0;

                while(!vis[currnode]){
                    vis[currnode]=true;
                    umap[currnode]=cnt;
                    cnt+=1;
                    int nxtnode=favorite[currnode];

                    if(umap.find(nxtnode)!=umap.end()){
                        int cyclelength=cnt-umap[nxtnode];
                        longcycle=max(longcycle,cyclelength);
                        vector<bool>visited(n,false);
                        if(cyclelength==2){
                            visited[currnode]=true;
                            visited[nxtnode]=true;
                            twolength+=2+bfs(currnode,adj,visited)+bfs(nxtnode,adj,visited);
                        }
                        break;
                    }

                    currnode=nxtnode;


                }

            }
        }
        return max(twolength,longcycle);
    }
};
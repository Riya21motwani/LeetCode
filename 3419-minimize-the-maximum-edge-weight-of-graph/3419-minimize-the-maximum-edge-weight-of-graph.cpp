class Solution {
public:

    bool possible(int mid, unordered_map<int,vector<pair<int,int>>>&adj, int n){
        vector<bool>vis(n,false);

        queue<int>q;
        q.push(0);
        vis[0]=true;

        while(!q.empty()){
            int node=q.front();

            q.pop();

            for(auto it:adj[node]){
                int newnode=it.first;
                int wt=it.second;
                if(wt<=mid && !vis[newnode]){
                    vis[newnode]=true;
                    q.push(newnode);
                }

            }
        }

        for(int i=1;i<n;i++){
            if(vis[i]==false){
                return false;
            }
        }

        return true;
    }


    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int,vector<pair<int,int>>>adj;
        int maxiwt=-1;

        //1st
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[v].push_back({u,wt});
            maxiwt=max(maxiwt,wt);
        }

        int l=0;
        int h=maxiwt;
        int ans=-1;

        while(l<=h){

            int mid=(l+h)/2;

            if(possible(mid,adj,n)==true){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;

    }
};
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        
       vector<vector<long long >>matrix(26,vector<long long>(26,1e9));
        int n=original.size();
        
        for(int i=0;i<n;i++){
            
            matrix[original[i]-'a'][changed[i]-'a'] = min((long long)cost[i],matrix[original[i]-'a'][changed[i]-'a'] );
            
        }
        
        
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        
         
        int m=source.size();
        long long ans=0;
        for(int i=0;i<m;i++){
           if(source[i]==target[i]){
               continue;
           }
            if(matrix[source[i]-'a'][target[i]-'a']==1e9){
                return -1;
            }
             ans+=matrix[source[i]-'a'][target[i]-'a'];
        }
        
        return ans;
    }
};
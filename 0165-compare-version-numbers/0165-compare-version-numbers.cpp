class Solution {
public:
    
    vector<string>gettoken(string version){
         
        stringstream ss(version);
        vector<string>tokens;
        string token="";
        while(getline(ss,token,'.')){
           tokens.push_back(token);
        }
        return tokens;
    }
    
    
    
    int compareVersion(string version1, string version2) {
       vector<string>v1=gettoken(version1);
        vector<string>v2=gettoken(version2);
        
        int m=v1.size();
        int n=v2.size();
        int i=0;
        while(i<m || i<n){

            int a=i<m?stoi(v1[i]):0;
            int b=i<n?stoi(v2[i]):0;
            if(a<b){
            return -1;
            }
            else if(a>b){
                return 1;
            }
            else{
                i++;
            }
        }
        return 0;
    }
};
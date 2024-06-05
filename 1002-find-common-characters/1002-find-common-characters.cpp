class Solution {
public:
    
    void findcnt( string &s, int temp[] ){
           for(int i=0;i<s.size();i++){
               char ch=s[i];
               temp[ch-'a']++;
               
           }
        
        
    }
    
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<string>result;
        int count[26]={0};
        for(int i=0;i<words[0].size();i++){
            char ch=words[0][i];
            count[ch-'a']++;
        }
 
        for(int i=1;i<words.size();i++){
              int temp[26]={0};
               findcnt(words[i],temp);
            
            for(int j=0;j<26;j++){
                 count[j]=min(count[j],temp[j]);
            }
            
            
        }
            
        for(int i=0;i<26;i++){
             int val=count[i];
            while(val--){
                
                   result.push_back(string(1,i+'a')) ;
             }
        }
            
         return result;   
    }
};
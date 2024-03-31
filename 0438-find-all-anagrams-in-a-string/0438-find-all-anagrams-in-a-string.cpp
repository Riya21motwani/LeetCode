class Solution {
public:
    
    bool isvalid( vector<int>&count){
         int n=count.size();
        for(auto& i:count){
           if(i!=0){
                  return false;
           }
        }
        return true;
    }
    
    
    
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        vector<int>count(26,0);
        for(int i=0;i<p.size();i++){
            count[p[i]-'a']++;
        }
        int n=s.size();
        int i=0;
        int j=0;
        while(j<n){

            
            count[s[j]-'a']--;
                
            if(j-i+1==p.size()){
                if(isvalid(count)){
                 res.push_back(i);
                }
                count[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};
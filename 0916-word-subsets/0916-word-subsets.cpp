class Solution {
public:

    bool ischeck(string &word1,vector<int>&umapfinal){
       
       vector<int> temp(26, 0);

            for(char &ch : word1) { 
                temp[ch-'a']++;
            }

            for(int i = 0; i < 26; i++) { 
            if(temp[i] < umapfinal[i]) {
                return false;
            }
        }
        return true;
      
          
    }


    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int>umapfinal(26);
         vector<string>ans;

         for(string &word:words2){
            vector<int>t(26,0);
            for(char ch:word){
                t[ch-'a']++;

                umapfinal[ch-'a']=max(umapfinal[ch-'a'],t[ch-'a']);
            }

         }

         for(string &word:words1){
            if(ischeck(word,umapfinal)){
                ans.push_back(word);
            }
         }


        return ans;

    }
};
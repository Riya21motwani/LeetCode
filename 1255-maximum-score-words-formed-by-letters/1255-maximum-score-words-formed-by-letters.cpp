class Solution {
public:
    int n;
    int  maximumscore;
    void solve(int idx, vector<string>& words,vector<int>&freq , vector<int>& score,int currscore){
       
        maximumscore=max(maximumscore,currscore);
        
        if(idx>=n){
               return;
        }
        //take
        int j=0; 
        int temp=0;
        vector<int>tempfreq=freq;
        while(j<words[idx].size()){
           
            char ch=words[idx][j];
            tempfreq[ch-'a']--;
            temp+=score[ch-'a'];
            if(tempfreq[ch-'a']<0){
               break;
            }
            j++;
        
        }
        
        if(j==words[idx].size()){
                  solve(idx+1,words,tempfreq,score,currscore+temp);
        }
        //not take
        
        solve(idx+1,words,freq,score,currscore);
        
    
    }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n=words.size();
        vector<int>freq(26,0);
        for(auto & ch:letters){
             freq[ch-'a']++;
        }
        maximumscore=INT_MIN;
        solve(0,words,freq,score,0);
        return maximumscore;
    }
};
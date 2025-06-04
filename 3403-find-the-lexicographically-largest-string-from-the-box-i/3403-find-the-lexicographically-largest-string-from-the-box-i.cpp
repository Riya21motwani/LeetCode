class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        string maxStr = "";
        if(numFriends==1){
            return word;
        }
        vector<int>v(26,0);
        int maxiind=-1;
        int ind=0;
        string dummy="";

        for(int i=0;i<n;i++){
           
            string temp=word.substr(i,min(n-(numFriends-1) , n-i));
            if(temp>dummy){
                dummy=temp;
            }

        }

     return dummy;

        
        
    }
};

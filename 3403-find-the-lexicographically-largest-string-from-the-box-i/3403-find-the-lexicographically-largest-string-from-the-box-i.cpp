class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends==1){
            return word;
        }
        int len = n - numFriends +1;

        string maxis="";
        string temp="";

        for(int i=0;i<n;i++){
            temp=word.substr(i,len);
            if(temp>maxis)
            maxis=temp;
        }

        return maxis;


        
       
    }
};

class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3){
            return false;
        }
        bool v=false;
        bool c=false;
        bool d=false;
        for(int i=0;i<n;i++){
            if(word[i]=='a' || word[i]=='e'|| word[i]=='i'|| word[i]=='o'|| word[i]=='u'|| word[i]=='A' || word[i]=='E'|| word[i]=='O'|| word[i]=='U'|| word[i]=='I'){
                v=true;
            }
            else if (isdigit(word[i])){
                d=true;
            }else if(word[i]=='@' || word[i]=='#' || word[i]=='$'){
                return false;
            }else{
                c=true;
            }
        }

        if(c==true && v==true){
            return true;
        }

        return false;
    }
};
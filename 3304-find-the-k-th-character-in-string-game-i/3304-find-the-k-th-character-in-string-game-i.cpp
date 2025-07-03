class Solution {
public:

    char f(string word, int cnt, int k){
        
        
        while(word.size()<k){
            string temp="";
            for(char i:word){
            if(i=='z'){
                temp+='a';
            }else{
           
                temp+=i+1;
            }
        }
        word+=temp;
        }
        return word[k-1];
    }

    char kthCharacter(int k) {
        if(k==1){
            return 'a';
        }
        string word="a";
        int cnt=0;
        return f(word,cnt,k);
    }
};
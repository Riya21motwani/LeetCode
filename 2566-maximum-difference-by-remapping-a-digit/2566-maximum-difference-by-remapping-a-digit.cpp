class Solution {
public:
    int minMaxDifference(int num) {
        string n1=to_string(num);
        string n2=to_string(num);
        char minval=n1[0];
        char maxval=n2[0];

        for(int i=0;i<n1.size();i++){
            if(n2[i]!='9'){
                maxval=n2[i];
                break;
            }
        }

        for(int i=0;i<n1.size();i++){
            if(n1[i]!='0'){
                minval=n1[i];
                break;
            }
        }
        for(int i=0;i<n1.size();i++){
            if(n1[i]==minval){
                n1[i]='0';
            }
            if(n2[i]==maxval){
                n2[i]='9';
            }
        }

        return stoi(n2)-stoi(n1);

     
        
    }
};
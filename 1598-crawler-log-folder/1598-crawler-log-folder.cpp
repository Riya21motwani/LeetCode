class Solution {
public:
    int minOperations(vector<string>& logs) {
        int initial=0;
        int n=logs.size();
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                if(initial!=0){
                initial-=1;
                }
            }else if(logs[i]=="./"){
                continue;
            }else{
                initial+=1;
            }
        }
        if(initial<0){

        return 0;
        }
        return initial;
    }
};
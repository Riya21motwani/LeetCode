class Solution {
public:

   
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        int n=digits.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j|| j==k|| i==k)continue;
                   
                    int a=digits[i];
                    int b=digits[j];
                    int c=digits[k];
                     if(a==0)continue;
                    if(c%2!=0)continue;
                    int number=a*100+b*10+c;
                    if(umap.find(number)==umap.end()){
                        ans.push_back(number);
                        umap[number]++;
                    }

                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
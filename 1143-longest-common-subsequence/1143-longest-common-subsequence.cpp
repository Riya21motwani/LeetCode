class Solution {
public:

    int f(int i , int j ,int n,int m,string &text1 ,string &text2){


        if(i==n && j==m){
            return 0;

        }
        if(i==n || j==m){
            return 0;
        }


       
       if(text1[i]==text2[j]){
        
        return 1+f(i+1,j+1,n,m,text1,text2);
        
       }

       return max(f(i,j+1,n,m,text1,text2) ,f(i+1,j,n,m,text1,text2) );
       

    }


    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
       

         return f(0,0,n,m,text1,text2);
    }
};
#include<bits/stdc++.h>
class Solution {
public:
    
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size();
        
         long long res=0;
       long long cnt_maxi=0;
       int maxi=*max_element(nums.begin(),nums.end());
        long long i=0,j=0;
        while(j<n){
         
             if(nums[j]==maxi){
                cnt_maxi++;
                 
             }
               while(cnt_maxi>=k){
                    res+=n-j;
                     if(nums[i]==maxi){
                      cnt_maxi--;
                        
                     }
                   i++;
                
               
            }
            j++;
        }
        return res;
    }
};
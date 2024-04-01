#include<bits/stdc++.h>
class Solution {
public:
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         int n=nums.size();
       
        unordered_set<int>u;
        int i=0;
        int j=0;
        while(j<n){
            
           
            if(abs(j-i)>k){
                u.erase(nums[i]);
                i++;
            }
            if(abs(j-i)<=k && u.find(nums[j])!=u.end()){
                    return true;
            }
            u.insert(nums[j]);
            j++;
            
            
            
            
            
            
        }
        return false;
    }
};
class Solution {
public:
    
    int dayrequired(vector<int>& weights,int mid){
        
        int day=1;
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            
            if(sum+weights[i]<=mid){
                    sum+=weights[i];
            }
            else{
              
             day+=1;
             sum=weights[i];
            }
        }
        return day;
    }
    
    int sum(vector<int>& weights){
         int n=weights.size();
        int s=0;
        for(int i=0;i<n;i++){
          s+=weights[i];
        }
        return s;
    }
    
    int maximum(vector<int>& weights){
           int n=weights.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,weights[i]);
        }
        return maxi;
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=maximum(weights);
        int h=sum(weights);
        int ans=sum(weights);
        while(l<=h){
            
            int mid=l+(h-l)/2;
            int dayreq=dayrequired(weights,mid);
             if(dayreq<=days){
                ans=mid;
                 h=mid-1;
             }else{
                l=mid+1;
             }
        
        }
        return l;
    }
};
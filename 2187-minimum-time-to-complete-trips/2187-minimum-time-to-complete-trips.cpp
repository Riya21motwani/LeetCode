class Solution {
public:
    
    bool possible(vector<int>& time, int totalTrips,  long long mid){
             
         long long n=time.size();
        long long sum=0;
        for(int i=0;i<n;i++){

         sum+=( mid)/time[i];
        }
        
        
        if(sum>=totalTrips){
                return true;
        }
    return false;
    }
        
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long n=time.size();
        long long l=1;
        long long h=( long long)*min_element(begin(time) ,end(time)) * totalTrips;
        
        while(l<h){
             long long mid=(l+(h-l)/2);
            
            if(possible(time,totalTrips , mid)){
                h=mid;
            }
            else{
                l=mid+1;
            }
            
        }
        return l;
    }
    
};




 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        if(n1>n2)return findMedianSortedArrays(nums2,nums1);
        int l=0;
        int h=n1;
        
        while(l<=h){
            int mid1=(l+h)/2;
            int left=(n1+n2+1)/2;
            int mid2=left-mid1;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            if(mid1<n1)r1=nums1[mid1];
            if(mid2<n2)r2=nums2[mid2];
            if(mid1-1>=0)l1=nums1[mid1-1];
            if(mid2-1>=0)l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                 if(n%2==1)return max(l1,l2);
                else{
                      return   (double) ( (double)(max(l1,l2))+ (double)(min(r1,r2)))/2;
                }
                
            }
            else if(l1>r2)h=mid1-1;
            else{
                 l=mid1+1;
               }
            }
        
        
      return 0;
        
    }
};
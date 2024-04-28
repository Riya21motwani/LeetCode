brute force approach
using merge sort
t.c=O(N+M)
s.c=O(N+M)

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int n=nums1.size();
        int m=nums2.size();
        vector<int> nums;
        int i=0;
        int j=0;
        while(i<n && j<m){
            
            if(nums1[i]<nums2[j]){

               nums.push_back(nums1[i]);
                i++;
            }
            else{
                     nums.push_back(nums2[j]);
                j++;
            }

        }
        
       while(i<n){
             nums.push_back(nums1[i]);
           i++;
           
       }
        while(j<m){
                 nums.push_back(nums2[j]);
            j++;
         }
         
        int t=nums.size();
        if( t%2==1){
            
           return nums[t/2];
        }
        return   (double) ( (double)(nums[t/2])+ (double)(nums[t/2-1]))/2;
    }
		
		//better approach
		//without using extra space
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int n=nums1.size();
        int m=nums2.size();
        vector<int> nums;
        int i=0;
        int j=0;
        
        int cnt=0;
         int newn=n +m;
        int ind2=newn/2;
        int ind1=newn/2-1;
        int indexel1=-1;
        int indexel2=-1;
        while(i<n&& j<m){
           if(nums1[i]<nums2[j]){
            if(cnt==ind1)indexel1=nums1[i];
            if(cnt==ind2)indexel2=nums1[i];
            cnt++;
            i++;
           }
            else{
              
            if(cnt==ind1)indexel1=nums2[j];
            if(cnt==ind2)indexel2=nums2[j];
            cnt++;
            j++;

            }
        }
        while(i<n){
             if(cnt==ind1)indexel1=nums1[i];
            if(cnt==ind2)indexel2=nums1[i];
            cnt++;
            i++;
        }
        while(j<m){
                if(cnt==ind1)indexel1=nums2[j];
            if(cnt==ind2)indexel2=nums2[j];
            cnt++;
            j++;
        }
       
        if( newn%2==1){
            
           return indexel2;
        }
        return   (double) ( (double)(indexel2)+ (double)(indexel1))/2;
    }
		
		//optimal approach 
		//based on symmetry
		// b.s in shorter array
		in case of even number of array
		we will see the symmetry 
		if  total 10 number then 5 on left ,5 on right 
		if we take 2 numbers from array1 then we will take 3  number from array2
		7  12 (l1) | 14(r1)  15
		1  2  3 (l2) |  4 (r2)   9  11
		
		l1>r2 then h=mid-1
		
		                  |    7 (r1)  14 15
		1  2  3 (l2) |  4 (r2)   9  11
		
		l2>r1 then l=mid+1
		
		
		l1=arr1[mid1-1]
		l2=arr2[mid2-1]
		r1=arr[mid1]
		r2=arr[mid2]
		
		median=max(l1,l2)+min(r1,r2)/2;
		

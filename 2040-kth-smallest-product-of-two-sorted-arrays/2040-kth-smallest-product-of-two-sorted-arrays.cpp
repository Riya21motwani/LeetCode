class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                long long p= (long long)nums1[i]*nums2[j];
                pq.push(p);
            }
        }
        if(k==1){
            return pq.top();
        }
        k--;
        while(!pq.empty()){
            int el=pq.top();
            pq.pop();
            k--;
            if(k==0){
                break;
            }
        }
        return pq.top();
    }
};
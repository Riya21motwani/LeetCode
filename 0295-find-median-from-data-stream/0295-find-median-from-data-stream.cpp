class MedianFinder {
public:
    //s1
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //s2
       if(pq1.empty() || num<pq1.top()){
          pq1.push(num);
       }else{
        pq2.push(num);
       }
        //s3
       if(pq2.size()>pq1.size()){
        pq1.push(pq2.top());
        pq2.pop();
       }else if(abs((int)pq1.size()-(int)pq2.size())>1){
        pq2.push(pq1.top());
        pq1.pop();
       }


    }
    
    double findMedian() {
       if(pq1.size()==pq2.size()){
        return (double)(pq1.top()+pq2.top())/2;
       }
       return (double)pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
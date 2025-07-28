class FreqStack {
public:
   unordered_map<int,int>umap;
   int maxi=0;
   unordered_map<int,stack<int>>track;
    FreqStack() {
        
    }
    
    void push(int val) {
       
     int freq=umap[val]+1;
     umap[val]=freq;

     if(freq>maxi){
        maxi=freq;
     }
     track[freq].push(val);


    }
    
    int pop() {
       int el=track[maxi].top();
       track[maxi].pop();
       if(track[maxi].empty()){
        maxi--;
       }
       umap[el]--;
       return el;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
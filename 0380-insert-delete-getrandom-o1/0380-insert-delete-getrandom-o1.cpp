class RandomizedSet {
public:
    unordered_map<int,int>umap;
    vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(umap.find(val)==umap.end()){
            v.push_back(val);
            umap[val]=v.size()-1;
            
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(umap.find(val)==umap.end()){
            return false;
        }
        int ind=umap[val];
        int lastval=v[v.size()-1];
 
        v[ind]=lastval;
        umap[lastval]=ind;

        umap.erase(val);
        v.pop_back();
        return true;

    }
    
    int getRandom() {
        int ind=rand()%v.size();
        return v[ind];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
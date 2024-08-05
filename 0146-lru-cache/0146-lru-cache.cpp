class LRUCache {
public:
    
    class Node{
        public:
        int key;
        int val;
        Node*prev;
        Node*next;
        
        Node(int key, int val){
            this->key=key;
            this->val=val;
        }
    };
    
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    
    int cap;
    unordered_map<int,Node*>umap;
    
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    
    void addNode(Node*newnode){
        Node*temp=head->next;
        temp->prev=newnode;
        newnode->next=temp;
        head->next=newnode;
        newnode->prev=head;
    }
    
    void deleteNode(Node*delnode){
        Node*prevv=delnode->prev;
        Node*nextt=delnode->next;
        prevv->next=nextt;
        nextt->prev=prevv;
    }
    
    int get(int key) {
        if(umap.find(key)!=umap.end()){
            Node*ans=umap[key];
            umap.erase(key);
            deleteNode(ans);
            addNode(ans);
            umap[key]=head->next;
            return ans->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(umap.find(key)!=umap.end()){
            Node*curr=umap[key];
            umap.erase(key);
            deleteNode(curr);
        }
        
        if(umap.size()==cap){
           umap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        
        addNode(new Node(key,value));
        umap[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
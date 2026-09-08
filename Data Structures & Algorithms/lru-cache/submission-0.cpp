class LRUCache {
public:
     class Node{
        public:
               int key,val;
               Node* prev;
               Node* next;

               Node(int k,int v){
                key=k;
                val=v;
                prev=next=NULL;
               }        
     };
      Node* head = new Node(-1,-1);
      Node* tail = new Node(-1,-1);
      int cap;
      unordered_map<int,Node*>m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(Node* newnode){
        Node* temp=head->next;
        head->next=newnode;
        temp->prev=newnode;
        newnode->prev=head;
        newnode->next=temp;
    }
    void delnode(Node* existnode){
        Node* prevnode=existnode->prev;
        Node* nextnode=existnode->next;
        prevnode->next=existnode->next;
        nextnode->prev=existnode->prev;
        
    }
    int get(int key) {
      if(m.find(key)!=m.end()){
        Node* resnode=m[key];
        int ans=resnode->val;
        m.erase(key);
        delnode(resnode);
        addnode(resnode);
        m[key]=resnode;
        return ans;
      }
      return -1;
    }
    
    void put(int key, int value) { //o(1)
         if(m.find(key) != m.end()){
          Node* existnode=m[key];
          m.erase(key);
          delnode(existnode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        Node* newnode=new Node(key,value);
        addnode(newnode);
        m[key]=newnode;
    }
};

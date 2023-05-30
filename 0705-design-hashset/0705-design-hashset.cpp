class MyHashSet {
public:
    map<int, int> mpp;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(mpp.find(key) == mpp.end())
        {
            mpp[key]++;
        }
    }
    
    void remove(int key) {
        if(mpp.find(key) != mpp.end())
        {
            mpp[key]--;
            if(mpp[key] == 0) mpp.erase(key);
        }
    }
    
    bool contains(int key) {
        if(mpp.find(key) != mpp.end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
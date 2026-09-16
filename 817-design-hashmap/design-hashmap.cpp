class MyHashMap {
private:
    static const int SIZE = 1000; // 1000 buckets
    vector<vector<pair<int,int>>> buckets; // each bucket is list of [key, value]

    int hash(int key) {
        return key % SIZE;
    }
public:
    MyHashMap() {
        buckets.resize(SIZE);
    }

    void put(int key, int value) {
        int h = hash(key);
        for(auto &p : buckets[h]) {
            if(p.first == key) {
                p.second = value; // update
                return;
            }
        }
        buckets[h].push_back({key, value});
    }

    int get(int key) {
        int h = hash(key);
        for(auto &p : buckets[h]) {
            if(p.first == key) return p.second;
        }
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        for(int i = 0; i < buckets[h].size(); i++) {
            if(buckets[h][i].first == key) {
                buckets[h].erase(buckets[h].begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
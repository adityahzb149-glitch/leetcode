class MyHashSet {
private:
    static const int SIZE = 1000;
    vector<vector<int>> buckets;

    int hash(int key) {
        return key % SIZE;
    }
public:
    MyHashSet() {
        buckets.resize(SIZE);
    }

    void add(int key) {
        int h = hash(key);
        for(int x : buckets[h]) {
            if(x == key) return; // already exists
        }
        buckets[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        for(int i = 0; i < buckets[h].size(); i++) {
            if(buckets[h][i] == key) {
                buckets[h].erase(buckets[h].begin() + i);
                return;
            }
        }
    }

    bool contains(int key) {
        int h = hash(key);
        for(int x : buckets[h]) {
            if(x == key) return true;
        }
        return false;
    }
};
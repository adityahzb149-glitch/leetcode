class RandomizedSet {
    vector<int> arr;
    unordered_map<int, int> mp; // val -> index in arr
public:
    RandomizedSet() {}

    bool insert(int val) {
        if(mp.count(val)) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val) {
        if(!mp.count(val)) return false;
        int idx = mp[val];
        int lastVal = arr.back();

        // swap with last element
        arr[idx] = lastVal;
        mp[lastVal] = idx;

        arr.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        int idx = rand() % arr.size();
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class LRUCache {
    int capacity;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        lru.splice(lru.begin(), lru, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->second = value, lru.splice(lru.begin(), lru, mp[key]);
            return;
        }
        if (lru.size() == capacity) mp.erase(lru.back().first), lru.pop_back();
        lru.push_front({key, value}), mp[key] = lru.begin();
    }
};

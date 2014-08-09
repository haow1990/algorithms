#include <unordered_map>
#include <list>
#include <utility>
#include <iostream>
using namespace std;

class LRUCache {
protected:
    typedef unordered_map<int, pair<int, list<int>::iterator> > cache_map_t;
    cache_map_t cache;
    list<int> lruKeyList;
    int capacity;
public:
    LRUCache(int capacityval) {
        capacity = capacityval;
    }

    int get(int key) {
        if (capacity <= 0) return -1;
        cache_map_t::iterator iter = cache.find(key);
        if (iter == cache.end()) {
            return -1;
        } else {
            lruKeyList.splice(lruKeyList.begin(), lruKeyList, iter->second.second);
            return iter->second.first;
        }
    }

    void set(int key, int value) {
        if (capacity <= 0) return;
        cache_map_t::iterator iter = cache.find(key);
        if (iter != cache.end()) {
            lruKeyList.splice(lruKeyList.begin(), lruKeyList, iter->second.second);
            iter->second.first = value;
        } else {
            if (cache.size() >= capacity) {
               int least = *lruKeyList.rbegin();
               cache.erase(least);
               lruKeyList.pop_back();
            }
            
            lruKeyList.push_front(key);
            cache[key] = pair<int, list<int>::iterator>(value, lruKeyList.begin());
        }
    }
};


int main()
{
    LRUCache cache(3);
    cout << cache.get(2) << endl;
    cache.set(2,4);
    cout << cache.get(2) << endl;
    cache.set(3,2);
    cache.set(5,3);
    cache.set(5,3);
    cache.set(2,8);
    cache.set(4,9);
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
    cout << cache.get(5) << endl;

    return 0;
}

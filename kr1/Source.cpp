#include <iostream>
#include <map>
#include <vector>
#include <optional>
using namespace std;


template <class K, class V> class LRUcache {
private:
    int size;
    map<K, int> counter_of_keys;
public:
    map<K, V> m_map;
    LRUcache(int capacity) {
        size = capacity;
    }
    optional<V> get(K key) {
        if (m_map.count(key) != 0) {
            if (counter_of_keys.count(key) == 0) {
                counter_of_keys[key] = 1;
            }
            else {
                counter_of_keys[key] += 1;
            }
            return m_map[key];
        }
        return nullopt;
    }

    void put(K key, V value) {
        if (m_map.size() != size) {
            m_map[key] = value;
        }
        else {
            K keey = key;
            auto last = counter_of_keys[key];
            for (auto el : counter_of_keys)
            {
                if (last < el.second) {
                    last = el.second;
                    keey = el.first;
                }
            }
            m_map.erase(keey);
            m_map[key] = value;
        }

    }
};
int main() {
    LRUcache <int, int> cache(2);
    cache.put(1, 1);
 
   // if (cache.get(1) != nullopt) cout << cache.get(1);
    
}
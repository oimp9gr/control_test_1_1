#include <iostream>
#include <map>
#include <vector>
#include <optional>

template <class K, class V>
class LRUCache {
public:
    LRUCache(const size_t & cap) : capacity(cap){
    };
    std::optional <V> get(const K& key) {
        if (mapa.count(key) != 0) {
            if (order.size() < capacity){
                order.push_back(key);
            } else {
                order.erase(order.begin());
                order.push_back(key);
            }
            return mapa[key];
        } else {
            return std::nullopt;
        }
    };
    void put(K key, V value) {
        if (capacity > mapa.size()) {
            mapa[key] = value;
            order.push_back(key);
        } else {
            mapa.erase(order[0]);
            order.erase(order.begin());
            order.push_back(key);
            mapa[key] = value;
        }
    }
private:
    std::vector<K> order;
    std::map<K, V> mapa;
    size_t capacity;
};


int main() {
    LRUCache<int, int> lRUCache (2);
    lRUCache.put(1, 1); // кеш равен {1=1}
    lRUCache.put(2, 2); // кеш равен {1=1, 2=2}
    std::cout << lRUCache.get(1).value();    // возвращает 1
    lRUCache.put(3, 3); // удаляется ключ 2, т.к. дольше всего не использовался, кеш равен {1=1, 3=3}
    lRUCache.get(2);    // returns std::nullopt (ключ не был найден)
    lRUCache.put(1, 4); // кеш равен {1=4, 3=3}
    lRUCache.put(5, 5); // удаляется ключ 3, т.к. дольше всего не использовался, кеш равен {1=4, 5=5}
    return 0;
}


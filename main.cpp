#include <iostream>
#include <optional>
#include <unordered_map>
#include <vector>

template<class K ,class V>
class LRUCache{
public:
    LRUCache(int capacity):capacity(capacity){}

    std::optional<V> get(K key){
        if(map.count(key) != 0 ){
            int counter = 0;
            for(auto i = 0 ; i < keys.size() ; i++){
                if(keys[i] == key) {
                    counter = i;
                    break;
                }
            }
            std::swap(keys[counter],keys[0]);
            return map[key];
        }
        return std::nullopt;
    }
    void put(K key, V value){
        if(map.count((key)) != 0){
            map[key] = value;
        }
        else{
            map[key] = value;
            keys.push_back(key);
            if(keys.size() > capacity){
                std::swap(keys[keys.size() - 1],keys[keys.size() - 2]);
                map.erase(keys[keys.size() - 1]);
                keys.pop_back();

            }
        }
    }
private:
    int capacity;
    std::unordered_map<K,V> map;
    std::vector<int> keys;
};



int main() {
    LRUCache<int, int> lRUCache (3);
    lRUCache.put(1, 1); // кеш равен {1=1}
    lRUCache.put(2, 2); // кеш равен {1=1, 2=2}
    lRUCache.get(1);    // возвращает 1
    lRUCache.put(3, 3); // удаляется ключ 2, т.к. дольше всего не использовался, кеш равен {1=1, 3=3}
    lRUCache.get(2);    // returns std::nullopt (ключ не был найден)
    lRUCache.put(1, 4); // кеш равен {1=4, 3=3}
    lRUCache.put(5, 5); // удаляется ключ 3, т.к. дольше всего не использовался, кеш равен {1=4, 5=5}
    lRUCache.put(5, 4);
    lRUCache.get(5);
    lRUCache.put(4, 4);
    lRUCache.put(4, 4);
    return 0;
}

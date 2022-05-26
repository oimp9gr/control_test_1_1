#include <iostream>
#include <optional>
#include <unordered_map>


template <class K, class V>
class LRUCache{
public:
    LRUCache(int capacity_) : capacity(capacity_) {}

    std::optional<V> get(K key){
    if (my_map.count(key) != 0 ){
        if (counter.count(key) == 0){
            counter[key] = 1;
        }
        else{
            counter[key] += 1;
        }
        return my_map[key];
    }
        return std::nullopt;

    }
    void put(K key, V value) {
        if (my_map.size() != capacity){
            my_map[key] = value;
        }
        else{
            auto min_it = std::min_element(counter.begin(), counter.end(), [](const auto& a, const auto& b) {
                return a.second < b.second;
            });

             my_map.erase(min_it->first);
             my_map[key] = value;

            }
        }
    std::unordered_map< K, V> my_map;


private:
    int capacity;
    std::unordered_map<K, int> counter;

};

int main() {

    LRUCache<int, int> lRUCache(2);
    lRUCache.put(1, 1); // кеш равен {1=1}
    lRUCache.put(2, 2); // кеш равен {1=1, 2=2}
    lRUCache.get(1);    // возвращает 1
    lRUCache.put(3, 3); // удаляется ключ 2, т.к. дольше всего не использовался, кеш равен {1=1, 3=3}
    lRUCache.get(2);    // returns std::nullopt (ключ не был найден)
    lRUCache.put(1, 4); // кеш равен {1=4, 3=3}
    lRUCache.put(5, 5); //


    std::cout << "Iterate and print keys and values of unordered_map,\n"
                 "using auto:\n";
    return 0;
}

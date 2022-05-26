#include <iostream>
#include <optional>
#include <map>
#include <vector>
using namespace std;


template <class K, class V> 
class LRUCache {
private:
	int size;
	map <K, int> count_keys;
public:
	map<K, V> my_map;
	LRUCache(int capacity) {
		size = capacity;
	}

	optional<V> get(K key) {
		if (my_map.count(key) != 0) {
			if (count_keys.count(key) == 0) {
				count_keys[key] = 1;
			}
			else {
				count_keys[key]++;
			}
			return my_map[key];
		}
		return nullopt;
	}

	void put(K key, V value) {
		if (my_map.size() != size) {
			my_map[key] = value;
		}
		else
		{
			auto min = count_keys[key];
			for (int i = 0; i < count_keys.size(); i++)
			{
				if (min < count_keys[key])
					min = count_keys[key];
			}
			my_map[key] = value;
		}
	}
};


int main() {
	LRUCache<int, int> lRUCache(2);
	lRUCache.put(1, 1); // кеш равен {1=1}
	lRUCache.put(2, 2); // кеш равен {1=1, 2=2}
	cout << lRUCache.get(1).value();    // возвращает 1
	lRUCache.put(3, 3); // удаляется ключ 2, т.к. дольше всего не использовался, кеш равен {1=1, 3=3}
	lRUCache.get(2);    // returns std::nullopt (ключ не был найден)
	lRUCache.put(1, 4); // кеш равен {1=4, 3=3}
	lRUCache.put(5, 5); // удаляется ключ 3, т.к. дольше всего не использовался, кеш равен {1=4, 5=5}
}


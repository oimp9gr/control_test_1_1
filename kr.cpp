#include <map>
#include <vector>
#include <optional>
using namespace std;
template<class K, class V>
class LRUCache {
	map<K, V> _map;
	int capasity;
	int count = 0;
	int last;
public:
	LRUCache(int _capasity) :capasity(_capasity) {}
  optional <V> get(const K& key) {
		if (_map.count(key) != 0) return _map[key];
		else return nullopt;
	}

	void put(const K& key, const V& value) {
		if (_map.count(key) == 0) {
			if (capasity == count) {
				_map.erase(last);
				_map[key] = value;
				last = key;
			}
			else {
				_map[key] = value;
				count++;
				last = key;
			}
		}
		else {
			_map[key] = value;
		}
	}

};


int main()
{
	LRUCache<int, int> lRUCache(2);
	lRUCache.put(1, 1); // кеш равен {1=1}
	lRUCache.put(2, 2); // кеш равен {1=1, 2=2}
	lRUCache.get(1);    // возвращает 1
	lRUCache.put(3, 3); // удаляется ключ 2, т.к. дольше всего не использовался, кеш равен {1=1, 3=3}
	lRUCache.get(2);    // returns std::nullopt (ключ не был найден)
	lRUCache.put(1, 4); // кеш равен {1=4, 3=3}
	lRUCache.put(5, 5); // удаляется ключ 3, т.к. дольше всего не использовался, кеш равен {1=4, 5=5}

}
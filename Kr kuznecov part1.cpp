#include <map>
#include <vector>
#include <optional>

template<class K, class V>
class LRUCache {
public:
	LRUCache(const int& capasity) :cap(capasity) {}

	//std::optional <V> get(const K& k) {  (base.count(k) != 0)? return base[k] : return std::nullopt; }
	std::optional <V> get(const K& k) {
		if (base.count(k) != 0) return base[k];
		else return std::nullopt;
	}

	void put(const K& key, const V& value) {
		if (base.count(key) == 0) {
			if (cap == counter) {
				base.erase(left);
				base[key] = value;
				left = key;
			}
			else {
				base[key] = value;
				counter++;
				left = key;
			}
		}
		else {
			base[key] = value;
		}
	}

private:
	std::map<K, V> base;
	int cap;
	int counter = 0;
	int left;
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



#include<iostream>
#include<optional>
#include<map>
using namespace std;


template <class k, class v> class lru
{
	int size;
	map<k, int> count;
	map <k, v> pair;
public:
	lru(int capacity) {
		size = capacity;
}
	optional<v> get(k key)
	{
		for (int i = 0; i < size; i++) {
			if (pair.count(key) != 0) {
				count[key] += 1;
			}
			return pair[key];
		}
		return nullopt;
	}
	

	void put(k key, v value) {
		if (pair.size() <= size) {
			pair[key] = value;
		}
		else {
			k keey = key;
			auto last = count[key];
			for (auto el:count)
			{
				if (last < el.second) {
					last = el.second;
					keey = el.first;
				}
			}
			pair.erase(keey);
			pair[key] = value;
		}
	}
};
int main()
{
	lru<int, int> lRUCache(2);
	lRUCache.put(1, 1); // кеш равен {1=1}
	lRUCache.put(2, 2); // кеш равен {1=1, 2=2}
	lRUCache.get(1);    // возвращает 1
	lRUCache.put(3, 3); // удаляется ключ 2, т.к. дольше всего не использовался, кеш равен {1=1, 3=3}
	lRUCache.get(2);    // returns std::nullopt (ключ не был найден)
	lRUCache.put(1, 4); // кеш равен {1=4, 3=3}
	lRUCache.put(5, 5); // удаляется ключ 3, т.к. дольше всего не использовался, кеш равен {1=4, 5=5}
}
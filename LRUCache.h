#pragma once
#include <map>
#include <vector>
#include <optional>
template<class K, class V>
class LRUCache {
private:
	int capacity_;
	std::map<K,V> main_c;
	int counter = 0;
	int last;
public:
	LRUCache(const int& c):capacity_(c) {
	}
	std::optional <V> get(const K& k) {
		if (main_c.count(k) != 0) {
			return main_c[k];
		} else
		return std::nullopt;
	}
	void put(const K& key, const V& value) {
		if (main_c.count(key) == 0) {
			if (capacity_ == counter) {
				main_c.erase(last);
				main_c[key] = value;
				last = key;
			}
		else {
			main_c[key] = value;

			counter++;
			last = key;
		}
		}
		else {
			main_c[key] = value;
		}
	}
};

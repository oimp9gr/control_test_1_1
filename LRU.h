#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<optional>

template<typename K, typename V>
class LRUCache {
	std::map<K, V> cache;
	std::map<K, int> frequency;
	int capacity;
public:
	LRUCache(int capacity_){ 
		capacity = capacity_;
	};

	std::optional<V> get(K key) {
		if (cache.contains(key)) {
			return cache[key];
		}
		return std::nullopt;
	};

	void put(K key, V value) {
		if (cache.contains(key) || cache.size() < capacity) {
			cache[key] = value;
			frequency[key] = 0;
		}
		else {
			K minKey;
			int min = INT_MAX;
			for (auto& item : frequency) {
				if (item.second < min) {
					min = item.second;
					minKey = item.first;
				}
			}
			cache.erase(minKey);
			frequency.erase(minKey);
			cache[key] = value;
			frequency[key] = 0;
		}
	}
};
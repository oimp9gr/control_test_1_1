#include<iostream>
#include<map>
#include "LRU.h"
#include "main.h"

int main() {
	LRUCache<int, int> lRUCache = new LRUCache(2);
	lRUCache.put(1, 1); // кеш равен {1=1}
	lRUCache.put(2, 2); // кеш равен {1=1, 2=2}
	lRUCache.get(1);    // возвращает 1
	lRUCache.put(3, 3); // удаляется ключ 2, т.к. дольше всего не использовался, кеш равен {1=1, 3=3}
	lRUCache.get(2);    // returns std::nullopt (ключ не был найден)
	lRUCache.put(1, 4); // кеш равен {1=4, 3=3}
	lRUCache.put(5, 5); // удаляется ключ 3, т.к. дольше всего не использовался, кеш равен {1=4, 5=5}
}
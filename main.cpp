#include<iostream>
#include<map>
#include "LRU.h"
#include "main.h"

int main() {
	LRUCache<int, int> lRUCache = new LRUCache(2);
	lRUCache.put(1, 1); // ��� ����� {1=1}
	lRUCache.put(2, 2); // ��� ����� {1=1, 2=2}
	lRUCache.get(1);    // ���������� 1
	lRUCache.put(3, 3); // ��������� ���� 2, �.�. ������ ����� �� �������������, ��� ����� {1=1, 3=3}
	lRUCache.get(2);    // returns std::nullopt (���� �� ��� ������)
	lRUCache.put(1, 4); // ��� ����� {1=4, 3=3}
	lRUCache.put(5, 5); // ��������� ���� 3, �.�. ������ ����� �� �������������, ��� ����� {1=4, 5=5}
}
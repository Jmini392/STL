//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		5월 6일                                                             (10주 2일)
//------------------------------------------------------------------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects
// Sequnce Container
// array<T, N> - 유일하게 크기 고정된 자료구조
// vector<T> - 캐시 효율성 (Cache Locality)
// list<T> - 임의의 위치에서 추가/제거 동작이 O(1)
// deque<T> - vector와 list의 장점을 활용하려는 자료구조
//------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include "save.h"
#include "YString.h"
using namespace std;

extern bool 관찰;

int main() {
	// vector, deque, list 어떤 것이 가장 많은 원소를 담을 수 있나
	{
		vector <int> v;
		while (true) {
			try {
				v.push_back(1);
			}
			catch (...) {
				cout << "vector<int> 개수 - " << v.size() << endl;
				break;
			}
		}
	}
	{
		deque<int> d;
		while (true) {
			try {
				d.push_back(1);
			}
			catch (...) {
				cout << "deque<int> 개수 - " << d.size() << endl;
				break;
			}
		}
	}
	{
		list<int> l;
		while (true) {
			try {
				l.push_back(1);
			}
			catch (...) {
				cout << "list<int> 개수 - " << l.size() << endl;
				break;
			}
		}
	}

	save("메인.cpp");
}


//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		3월 18일                                                             (3주 2일)
//------------------------------------------------------------------------------------------------------------
// 많은 수의 자료를 처리하기 - binary I/O
//------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <print>
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0, 9999 };
uniform_int_distribution uidNameLen{ 10, 30 };
uniform_int_distribution<int> uidChar{ 'a', 'z' };

class Dog {
public:
	Dog() {
		num = uid(dre);
		size_t len = uidNameLen(dre);
		for (int i = 0; i < len; ++i) {
			name += uidChar(dre);
		}
	}
	string getName() const { return name; }
private:
	string name;				// 10 이상 30 이하 임의의 소문자
	int num;

	friend ostream& operator<<(ostream& os, const Dog& dog) {
		print("[{:4}] - {} ", dog.num, dog.name);
		return os;
	}
};

int main() {
	array<Dog, 1000> dogs;

	// 이름 순으로 정렬하라
	sort(dogs.begin(), dogs.end(), [](const Dog& a, const Dog& b) {
		return a.getName() < b.getName();
		});

	for (const Dog& dog : dogs) {
		cout << dog << endl;
	}

	save("메인.cpp");
}


//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		4월 21일                                                             (8주 1일)
// 4월 22일 중간고사 예정
//------------------------------------------------------------------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects
// array<T, N> - 유일하게 크기 고정된 자료구조
// vector<T> - dynamic array
//------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>
#include <array>
#include "save.h"
#include "YString.h"
using namespace std;

extern bool 관찰;

int main() {
	save("메인.cpp");
	
	array<int, 26> alpha{};
	// [문제] "메인.cpp"의 소문자 개수를 세서 다음과 같이 출력하라
	// a - 10
	// b - 3
	// ...
	// z - 0

	ifstream in { "메인.cpp" };
	if (not in)
		return 20260421;

	char c;
	while (in >> c) {
		if (islower(c)) {
			++alpha[c - 'a'];
		}
	}

	for (int i = 0; i < alpha.size(); ++i)
		cout << static_cast<char>('a' + i) << " - " << alpha[i] << endl;
}


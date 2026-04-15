//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		4월 15일                                                             (7주 2일)
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
#include "save.h"
#include "YString.h"
using namespace std;

extern bool 관찰;

int main() {
	// [문제] 키보드에서 입력한 정수의 합을 출력하라.

	int sum = accumulate(istream_iterator<int>(cin), {}, 0);

	cout << "합: " << sum << endl;

	save("메인.cpp");
}


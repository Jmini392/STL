//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		3월 25일                                                             (4주 2일)
//------------------------------------------------------------------------------------------------------------
// callable type
//------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <array>
#include <print>
#include <ranges>
#include "save.h"
using namespace std;

// 랜덤값을 갖는 int 1000만개를 메모리에 저장하라.
// 오름차순으로 정렬한 후 화면에 출력하라.

default_random_engine dre;
uniform_int_distribution uid{ 0, 999'9999 };

array<int, 1000'0000> a;

int 오름차순 (const void * a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	for (int& num : a)
		num = uid(dre);
	
	// 여기서 qsort를 사용하여 오름차순으로 정렬하라
	qsort(a.data(), a.size(), sizeof(array<int,1000'0000>::value_type), 오름차순);

	cout << "정렬 후 - 앞에서 부터 1000개만 출력" << endl;
	for (int num : a | views::take(1000))
		print("{:8}", num);

	save("메인.cpp");
}


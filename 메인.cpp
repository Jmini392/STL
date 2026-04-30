//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		4월 29일                                                             (9주 2일)
//------------------------------------------------------------------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects
// array<T, N> - 유일하게 크기 고정된 자료구조
// vector<T> - dynamic array -> random access(임의의 위치에 접근이 O(1))
// list<T> - 임의의 위치에서 추가/제거 동작이 O(1)
//------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <vector>
#include "save.h"
#include "YString.h"
using namespace std;

extern bool 관찰;

int main() {
	save("메인.cpp");

	// [문제] 파일에 있는 단어를 list에 저장하라.
	// list를 사전기준으로 오름차순 정렬하라.
	// 화면에 출력하라

	ifstream in{ "2026 1학기 STL.txt" };
	if (not in) return 20260429;

	cout << "파일 읽는중";
	list<YString> cont{ istream_iterator<YString>{in}, {} };
	cout << endl;

	cont.sort([](const YString& a, const YString& b) {
		return lexicographical_compare(a.data(), a.data() + a.size(), b.data(), b.data() + b.size());
		});

	for (const YString& ys : cont) {
		cout << ys << endl;
	}
}


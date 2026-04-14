//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		4월 8일                                                              (6주 2일)
// 4월 22일 중간고사 예정
//------------------------------------------------------------------------------------------------------------
// STL 컨테이너 - std::string을 코딩하여 STL 컨테이너에 필요한 것들을 알아본다
//------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "YString.h"
using namespace std;

extern bool 관찰;

int main() {
	array<YString, 5> a{ "333", "1", "55555", "4444", "22" };
	
	관찰 = true;
	// 오름차순으로 정렬하라
	sort(a.begin(), a.end(), [](const YString& a, const YString& b) {
		return a.Getlen() < b.Getlen();
	});
	관찰 = false;

	for (YString& s : a) {
		cout << s << endl;
	}
	
	save("메인.cpp");
}


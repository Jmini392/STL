//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		5월 12일                                                            (11주 1일)
//------------------------------------------------------------------------------------------------------------
// span<T> -> T[N], arrat<T,N>, vector<T>, string{ string_view }, YString : contiguous / light weight object
// STL iterator
//------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <ranges>
#include <span>
#include "save.h"
#include "YString.h"
using namespace std;

extern bool 관찰;

int main() {
	YString ys{ "The quick brown fox jumps over the lazy dog" };

	sort(ys.data(), ys.data() + ys.size());

	// [문제] 거꾸로 출력하라
	span<char> s{ ys.data(), ys.size() };
	for (char c : s | views::reverse) 
		cout << c << " ";
	cout << endl;

	save("메인.cpp");
}


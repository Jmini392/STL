//----------------------------------------------------------------------------------------------------------
// 한 학기 강의를 저장하는 함수
// 
// 2026. 3. 4
//----------------------------------------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include "save.h"

void save(const std::string& fname) {
	std::cout << "\"" << fname << "\" 저장합니다" << '\n';

	std::ifstream in{ fname };		//RAII (Resource Acquisition Is Initialization)
	if (not in) {
		std::cout << fname << " - 열 수 없습니다" << '\n';
		exit(20260304);
	}

	std::ofstream out{ "2026 1학기 STL.txt", std::ios::app };

	// 저장한 시간을 out의 기록하자
	// std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	// 시간을 한글로 저장하자
	auto now = std::chrono::system_clock::now(); // auto는 컴파일러가 타입을 추론한다
	using namespace std::chrono_literals;

	out << '\n';
	out << "-------------------------------------------------" << '\n';
	out << "저장시간 - " << now + 9h << '\n';
	out << "-------------------------------------------------" << '\n';
	out << '\n';

	// in의 내용을 읽어서 out에 덧붙이자.
	// std::copy(원본, 복사본);
	std::copy(std::istreambuf_iterator<char>{in}, {}, std::ostream_iterator<char>{out});
}

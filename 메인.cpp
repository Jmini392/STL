//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		4월 1일                                                              (5주 2일)
//------------------------------------------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <array>
#include <ranges>
#include <fstream>
#include "save.h"
using namespace std;

class Dog {
public:
	int getId() const { return id; }
	string getName() const { return name; }
private:
	string name;	// [1 , 16]
	int id;			// [1, 999'9999]
};

// [문제] 바이너리 파일 "Dog천만마리"에는 Dog 객체 write로 천만객체를 기록하였다.
// array에 모든 객체를 읽어와라.
// 앞에서 100개를 화면에 출력하라.

array <Dog, 1000'0000> dogs;

int main() {
	ifstream in{ "Dog천만마리", ios::binary };
	if (not in) {
		cout << "파일을 열 수 없습니다." << endl;
		return 1;
	}
	
	save("메인.cpp");
}


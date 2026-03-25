//------------------------------------------------------------------------------------------------------------
// 2026 1학기 STL 화56 수34		3월 25일                                                             (4주 2일)
//------------------------------------------------------------------------------------------------------------
// CALLABLE TYPE
//------------------------------------------------------------------------------------------------------------
#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"
USING NAMESPACE STD;

// [문제] "메인.CPP"에 있는 글자 중에서 소문자는 모두 대문자로 바꿔(다른건 그대로)
// "메인대문자.CPP"에 저장하라.

INT MAIN() {
	IFSTREAM IN{ "메인.CPP" };
	IF (NOT IN) {
		COUT << "파일을 확인하세요." << ENDL;
		RETURN 20260325;
	}

	OFSTREAM OUT{ "메인대문자.CPP" };
	
	// TRANSFORM(원본파일의시작, 끝, 변신한파일의시작, 변신방법);
	TRANSFORM(ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, OSTREAMBUF_ITERATOR<CHAR>{OUT},
		[](CHAR C) { RETURN TOUPPER(C); });

	SAVE("메인.CPP");
}


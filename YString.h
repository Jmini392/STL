//-----------------------------------------------------------------------------------------------
// STL의 내부를 들여다 보려고 만든 YString
//
// 2026. 4. 8 시작
// 복사 생성자 - 2026. 4. 8
// 이동 생성자 - 2026. 4. 8
//-----------------------------------------------------------------------------------------------
#pragma once
#include <memory>

class YString {
public:
	YString();
	~YString();

	YString(const char* s);

	YString(const YString&);
	YString& operator=(const YString&);

	// C++11 move semantics
	YString(YString&&) noexcept;
	YString& operator=(YString&&) noexcept;

	void special(std::string);		// 클래스의 special함수를 관찰하려는 목적

	size_t Getlen() const;
	void show();			// 2026. 4. 21 special한 순간이 아닐때 관찰하려고

	// 표준컨테이너라면 다음 멤버를 제공해야한다
	size_t size() const;		// 2026. 4. 21
	char* data() const;			// 2026. 4. 21
private:
	size_t id{ };
	size_t len{ };
	std::unique_ptr<char[]> p{ };

	static size_t gid;				// 생성 시 부여될 고유번호

	friend std::ostream& operator<<(std::ostream& os, const YString& ys);
};
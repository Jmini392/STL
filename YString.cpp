//-----------------------------------------------------------------------------------------------
// STL의 내부를 들여다 보려고 만든 YString
//
// 2026. 4. 8 시작
//-----------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <print>
#include "YString.h"

bool 관찰{ false };
size_t YString::gid{};

YString::YString() : id{ ++gid } {
	if (관찰) {
		special("디폴트");
	}
}

YString::~YString() {
	if (관찰){
		special("소멸");
	}
}

YString::YString(const char* s) : id{ ++gid } {
	len = strlen(s);
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);
	
	if (관찰) {
		special("생성(*)");
	}
}

// 2026. 4. 8
YString::YString(const YString& other) : id{ ++gid } {
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰) {
		special("복사생성");
	}
}

YString& YString::operator=(const YString& other) {
	// 자기 자신을 할당할 이유는 없다.
	if (this == &other) return *this;

	// 먼저 나를 정리 - p의 동작을 알아봐야 한다
	p.release();
	
	// 나를 other와 같게 만든다
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰) {
		special("복사할당");
	}

	return *this;
}

// 2026. 4. 8  C++11 move semantics
YString::YString(YString&& other) : id{ ++gid } {
	id = other.id;
	p.reset(other.p.release());

	other.len = 0;
	
	if (관찰) {
		special("이동생성");
	}
}

YString& YString::operator=(YString&& other) {
	if (this == &other) return *this;

	p.release();

	len = other.len;
	p.reset(other.p.release());

	other.len = 0;

	if (관찰) {
		special("이동할당");
	}
	
	return *this;
}

// 2026. 4. 8
size_t YString::Getlen() const {
	return len;
}

std::ostream& operator<<(std::ostream& os, const YString& ys) {
	for (int i = 0; i < ys.len; ++i)
		os << ys.p.get()[i];
	return os;
}

void YString::special(std::string 동작) {
	if (관찰) {
		std::string 글자;
		size_t printNum = 10;
		if (len < printNum) printNum = len;
		for (int i = 0; i < len; ++i)
			글자 += p.get()[i];

		println("[{:8}] {:8} - 객체:{:#016X} 글자:{:#016X} 개수:{:<4} 내용:{}",
			id, 동작, (unsigned long long)this, (unsigned long long)p.get(), len, 글자);
	}
}
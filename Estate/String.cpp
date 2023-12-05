#include "String.h"
#include <string>
#include <iostream>
#pragma warning (disable : 4996)

std::ostream& ASD::operator << (std::ostream& c, ASD::String& s) {
	return c << s.get();
}

ASD::String ASD::operator + (const char* s1, ASD::String& s2) {
	return ASD::String(s1).add(s2.get());
}

ASD::String::String(char c, size_t len) {
	str = new char[len + 1];
	for (size_t i = 0; i < len; i++) {
		str[i] = c;
	}
	str[len] = 0;
}

ASD::String& ASD::String::add(const char* s) {
	if (!s) return *this;
	size_t nlen = length() + strlen(s) + 1;
	char* nstr = new char[nlen];
	nstr[0] = 0;
	if (str) strcpy_s(nstr, nlen, str);
	strcat_s(nstr, nlen, s);
	delete str;
	str = nstr;
	return *this;
}

ASD::String& ASD::String::remove(size_t pos, size_t count) {
	pos -= 1;
	size_t len = this->length();
	if (pos<0 || pos + count - 1>len - 1 || count < 1) return *this;
	for (int i = pos; i < len; i++) {
		this->str[i] = this->str[i + count];
		if (i > len - 1 - count) {
			this->str[i] = 0;
		}
	}
	return *this;
}

ASD::String& ASD::String::insert(size_t pos, const char* s) {
	pos -= 1;
	size_t nlen = length() + strlen(s) + 1;

	if (pos<0 || pos>this->length() - 1) return *this;
	char* nstr = new char[nlen];
	int j = 0, a = 0;
	for (int i = 0; i < nlen; i++) {
		if (i < pos) {

			nstr[i] = this->str[j];
			j++;
		}
		else if (i > pos + strlen(s) - 1) {
			nstr[i] = str[j];
			j++;
		}
		else {
			nstr[i] = s[a];
			a++;
		}
	}

	this->empty();
	this->str = nstr;

	return *this;
}
bool ASD::String::find(const char* s) {
	bool res = 0;
	int j = 0;
	if (this->length() - strlen(s) > -1) return res;
	for (int i = 0; i < this->length() - strlen(s) + j + 1; i++) {
		if (this->str[i] == s[j]) {
			j++;
		}
		else {
			j = 0;
		}
		if (j == strlen(s)) {
			res = 1;
			break;
		}
	}

	return res;
}

void ASD::String::reverse() {
	if (!this->length()) return;

	this->str = strrev(this->str);
}

void ASD::String::countCharacters() { //int &* charCount
	const int ASCII_SIZE = 256;
	int charCount[ASCII_SIZE] = { 0 };
	for (int i = 0; i < this->length(); i++) {
		charCount[this->str[i]]++;
	}

	// ����� ����������
	for (int i = 0; i < ASCII_SIZE; ++i) {
		if (charCount[i] > 0) {
			std::cout << "Character: " << static_cast<char>(i) << ", Count: " << charCount[i] << ", ASCII: " << i << std::endl;
		}
	}
}

bool ASD::String::hasCapitalLetter() {
	for (int i=0; this->str[i]; i++) {
		char s = this->str[i];
		if (s >= 'A' && s <= 'Z') {
			return true;
		}
	}
	return false;
}

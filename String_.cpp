#pragma once
#include "String_.h"
#include <iostream>
#include <cstring>
#include <Windows.h>

namespace ASD {

	string::string() {
		str = nullptr;
		size = 0;
	}

	string::string(char* str)
	{
		size = strlen(str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		this->str[size] = '\0';
	}

	string::~string(){
		delete[] this->str;
	}

	string& string::add(const char* str) {

		if (!str) return *this;

		unsigned long long new_size = size + strlen(str) + 1;
		char* new_str = new char[new_size];
		new_str[0] = 0;

		if (this->str) strcpy_s(new_str, new_size, this->str);
		strcat_s(new_str, new_size, str);

		if (this->str) delete this->str;

		this->str = new_str;
		size = new_size - 1; //???

		return *this;
	}

	int string::find_substr(const char* word, int number) {
		unsigned int len = strlen(word), j = 0, protect = 0;

		int i = 0;

		bool find = false;

		if (number < 0)
			for (i = (int)size - 1, j = len - 1; i >= 0; i--) {

				if (str[i] == word[j]) { protect++; j--; }

				else if (protect && word[i] != str[j]) { protect = 0; j = len - 1; i++; }

				else continue;

				if (protect == len) { find = true; break; }

			}

		else for (; i < (int)size; i++) {

			if (str[i] == word[j]) { protect++; j++; }

			else if (protect && word[j] != str[i]) { protect = 0; j = 0; i--; }

			else continue;

			if (protect == len) { find = true; i -= len - 1; break; }


		}

		return ((find) ? i : -1);
	}

	int string::length()
	{
		this->size = strlen(this->str);
		return this->size;
	}

	string& string::erase(const char* substr, int x, int y) {
		int k = 0;
		int size = strlen(substr);
		char s2[255];
		for (int t = 0; t < x; t++) { s2[k] = substr[t]; k++; }
		for (int t = x + y; t < size; t++) { s2[k] = substr[t]; k++; }
		delete str;
		str = s2;


		return *this;
	}

	string& string::cut(char x, char y) {
		char* s = new char[strlen(str)+1];
		int j = 0; 
		for (int i = 0; str[i]; i++) {
			if(str[i]==x){
				if (i == 0 || str[i] != str[i-1]) {
					s[j] = y;
					j++;
				}
			}
			else {
				s[j] = str[i];
				j++;
			}
		}
		s[j] = 0;
		//delete str;
		str = s;

		return *this;

	}

	int string::find(const char* substr) {
		//strpos
		if (!substr[0])return -1;
		//int c = strlen(substr);
		int j = 0; 
		int pos = -1;
		for (int i = 0; str[i]; i++) {
			if (str[i] == substr[j]) {
				if(j == 0)pos = i;
				j++;
				if (!substr[j])break;
			}
			else {
				j = 0;
				pos = -1;
			}

			/*for (int j = 0; j < strlen(substr); j++) {
				if (str[i] == substr[j]) {
					return i;
				}
				else {
					int z = -1;
					return z;
				}
			}*/

		}
		return pos;

		/*if (new_size == strlen(substr)) std::cout << "\ntrue";
		else std::cout << "\nfalse";*/

		//return *this;
	}

	string& string::insert(unsigned int x, const char v)
	{
		if (!x || !v) return *this;

		unsigned int new_size = size + 2;
		char* new_str = new char[0];
		new_str[0] = 0;
		//strcpy_s(new_str, new_size, str);

		for (int i = 0; i < new_size; i++) {
			if (i == x) {
				new_str[i] = v;
				new_str[i + 1] = str[i];
			}
			else if (i<x || i > x + 1) new_str[i] = str[i];
		}

		if (str) delete str;

		str = new_str;

		return *this;
	}

	string& string::replace_letters(const char a, const char b)
	{
		if (!a || !b) return *this;

		unsigned int new_size = size + 2;
		char* new_str = new char[0];
		new_str[0] = 0;

		for (int i = 0; i < new_size; i++) {
			if (str[i] == a) {
				new_str[i] = b;
			}
			else new_str[i] = str[i];
		}

		if (str) delete str;

		str = new_str;

		return *this;
	}

	string& string::operator+(const char* str) {
		add(str);
		return *this;
	}

	string& string::operator+(int y)
	{
		char str[10] = { 0 };//tipo rasmer int

		_itoa_s(y, str, 10/*sistema schislenia*/);
		//atoi
		add(str);

		return *this;
	}
	void string::input() {
		char s[10000];
		cout << "¬ведите строку:\n";
		gets_s(s);
		gets_s(s);
		this->str = s;
	}

	string& string::operator=(const string &other)
	{
		if (this->str != nullptr) {
			delete[] str;
		}

		size = strlen(other.str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[size] = '\0';
		return *this;
	}

	istream& operator >>(istream& in, string& s) {
		char* buf = new char[100001];
		in.getline(buf, 100000);
		s.size = strlen(buf);
		s.str = new char[s.size];
		for (int i = 0; i < s.size; ++i)
			s.str[i] = buf[i];
		delete[] buf;
		return in;
	}
	ostream& operator <<(ostream& out, string s) {
		for (int i = 0; i < s.size; ++i)
			out << s.str[i];
		return out;
	}

}


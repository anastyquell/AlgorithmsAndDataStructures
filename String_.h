#pragma once

#include <iostream>
#include <cstdarg>
#include <stdio.h>
using namespace std;
namespace ASD {
	class string {

		unsigned long long size;

	public:
		char* str;
		char first;

		string();
		string(char *str);
		~string();
		string& add(const char* str);
		void input();
		int find(const char* substr);

		int find_substr(const char* substr, int);
		int length();

		string& insert(unsigned int x, const char v);

		string& replace_letters(const char a, const char b);

		char& operator [](int i) { return str[i]; }

		string& operator +(const char* str);

		string& operator +(int y);
		string& operator =(const string& other);
		friend istream& operator >>(istream& in, string& s);
		friend ostream& operator <<(ostream& out, string s);

		string& erase(const char* substr, int x, int y);

		string& cut(char x, char i);
	};
};

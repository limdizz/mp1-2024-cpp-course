#pragma once

class String
{
private:
	char* str;
	int size;
public:
	String(int size = 0);
	String(const char* s);
	String(const String& s);
	~String();

	int getLength() const;

	String& operator=(const String& s);
	String operator+(const String& s);
	String& operator+=(const String& s);

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
};


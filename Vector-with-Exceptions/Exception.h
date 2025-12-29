#pragma once
#include <string>
#include <iostream>

class Exception
{
	std::string File, Function;
	int Line;
	std::string Descr;

public:
	Exception(const char *_File, const char *_Function, int _Line, const char *_Descr);
	Exception();
	~Exception();

	friend std::ostream &operator<<(std::ostream &os, const Exception &ex);
};

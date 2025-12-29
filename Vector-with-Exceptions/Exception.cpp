#include "Exception.h"

Exception::Exception(const char *_File, const char *_Function, int _Line, const char *_Descr)
{
	File = _File;
	Function = _Function;
	Line = _Line;
	Descr = _Descr;
}

Exception::Exception() : File(""), Function(""), Line(0), Descr("") {}

Exception::~Exception() {}

std::ostream &operator<<(std::ostream &os, const Exception &ex)
{
	os << "File: " << ex.File << "\n";
	os << "Function: " << ex.Function << "\n";
	os << "Line: " << ex.Line << "\n";
	os << "Description: " << ex.Descr << "\n";
	return os;
}

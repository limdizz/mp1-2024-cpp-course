#include "Exception.h"
int main()
{
    Exception ex1(__FILE__, "main", __LINE__, "Test exception");
    std::cout << ex1 << std::endl;
}

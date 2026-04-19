#include <iostream>
#include <iomanip>
#include "header.h"
#include <cstdio>
void showByte(byte_pointer start, size_t len);

int main()
{
    int i = 0xff;
    float f = 5.0;
    float f2 = 1.0;
    float f3 = 12345.0;
    double d = 12345.00;
    showByte((byte_pointer)&i, sizeof(i));
    showInt(i);
    showFloat(f2);
    showFloat(f3);
    showDouble(d);
    std::cout << is_little_endian();
    return 0;
}

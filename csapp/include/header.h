#include <iostream>
#ifndef SHOW_BYTE_H
#define SHOW_BYTE_H
using byte_pointer = unsigned char*;

void showByte(byte_pointer, size_t );
bool is_little_endian();
void showShort(short x);
void showInt(int x);
void showLong(long x);
void showFloat(float x);
void showDouble(double x);
void showPointer(void *x);
#endif
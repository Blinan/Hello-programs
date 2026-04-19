#include <iostream>
#include <iomanip>
#include "header.h"

void showByte(byte_pointer start, size_t len)
{
    for(size_t i = 0; i < len; ++i){
       std::cout  << std::hex <<std::setfill('0') << std::setw(2) 
       << static_cast<unsigned>(start[i]) ;    //Ubuntu24.04使用小端法输出，详见CSAPP-P29
       // printf("%.2x",start[i]);
    }
    std::cout << std::endl;
}
bool is_little_endian(){
    int x=1;
    if(*((byte_pointer) &x) == 0x01)return 1;
    else return 0;
}
void showShort(short x){
    showByte((byte_pointer) &x, sizeof(short));
}
void showInt(int x){
    showByte((byte_pointer) &x, sizeof(int));
}
void showLong(long x){
    showByte((byte_pointer) &x, sizeof(long));
}
void showFloat(float x){
    showByte((byte_pointer) &x, sizeof(float));
}
void showDouble(double x){
    showByte((byte_pointer) &x, sizeof(double));
}
void showPointer(void *x){
    showByte((byte_pointer) &x, sizeof(void *));
}


#include <iostream>
#include <utility>

int main()
{
    int i = 5;
    int *p = new int;
    *p = 99;
    int &&r = i * 5;
    int &&m = std::move(i);
    std::cout << "m = " << m << std::endl;
    i = 10;
    *p = 81;
    std::cout << "r = "<< r << ","
    << "m = " << m << ","
    << "i = " << i << "." << std::endl;
    std::cout << "s";
    return 0;
}
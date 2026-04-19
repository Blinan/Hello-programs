#include <iostream>
#include <curl/curl.h>

int main()
{
    std::cout << LIBCURL_VERSION_NUM << std::endl;
    return 0;
}